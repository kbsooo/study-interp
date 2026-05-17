# 01. Mechanistic Interpretability Roadmap

## 목표

논문 제목을 많이 아는 것보다, 작은 transformer에서 **내가 직접 causal evidence를 만든다**가 목표다.

최소 모델:

- GPT-2 small
- TinyStories 계열 모델
- 가능하면 작은 toy transformer

주요 도구:

- Python / PyTorch
- TransformerLens
- matplotlib / plotly
- pandas
- optional: SAELens

## Phase 0 — 현재 notebook 정리

이미 있는 파일: `mech-interp/transformerlens.ipynb`

현재 들어있는 핵심 실험:

1. GPT-2 로딩
2. logits/top-k prediction 확인
3. cache activation 이름과 shape 보기
4. attention pattern 시각화
5. zero ablation
6. clean/corrupt activation patching

### 해야 할 수정

각 markdown cell을 아래 질문에 답하게 바꾼다.

- 이 cell의 목적은 무엇인가?
- 입력 shape/output shape는 무엇인가?
- 이 결과가 모델 내부에 대해 말해주는 것은 무엇인가?
- 다음 실험으로 이어지는 질문은 무엇인가?

### 완료 기준

- [ ] notebook을 처음부터 끝까지 재실행해도 에러가 없다.
- [ ] `cache`의 주요 key 10개를 설명할 수 있다.
- [ ] attention pattern 그림 하나를 저장한다.
- [ ] ablation 전후 top-k 또는 logit diff를 표로 남긴다.

---

## Phase 1 — TransformerLens 기본기

### Task 1. Tokenization/logits 이해

실험:

```python
prompt = "The capital of France is"
tokens = model.to_tokens(prompt)
str_tokens = model.to_str_tokens(prompt)
logits, cache = model.run_with_cache(prompt)
```

해야 할 것:

- `tokens.shape` 확인
- 각 token string 출력
- final position logits의 top-10 token 출력
- 정답 token logit rank 계산

완료 기준:

- [ ] “왜 final position만 보나?” 설명 가능
- [ ] logit, probability, rank의 차이 설명 가능
- [ ] tokenization 때문에 생기는 공백 token 문제를 설명 가능

### Task 2. Residual stream 지도 그리기

봐야 할 hook:

- `hook_embed`
- `hook_pos_embed`
- `blocks.{L}.hook_resid_pre`
- `blocks.{L}.hook_resid_mid`
- `blocks.{L}.hook_resid_post`
- `ln_final.hook_normalized`

해야 할 것:

- 각 activation shape 표 만들기
- layer별 residual norm plot
- position별 residual norm plot

완료 기준:

- [ ] residual stream이 “정보가 누적되는 통로”라는 말을 shape와 함께 설명 가능
- [ ] layer/position 차원을 헷갈리지 않음

### Task 3. Attention pattern 읽기

실험:

- layer 0~11, head 0~11의 attention pattern을 시각화
- 특정 head가 어떤 token을 보는지 top attention target 출력

주의:

attention pattern은 causal evidence가 아니다. “봤다”는 사실만 말한다. 실제로 출력에 중요했는지는 ablation/patching으로 확인해야 한다.

완료 기준:

- [ ] attention heatmap 3개 저장
- [ ] “attention is not explanation”을 본인 말로 설명 가능

---

## Phase 2 — Causal intervention 기본

## 핵심 metric: logit difference

예시:

```python
answer = model.to_single_token(" Paris")
wrong = model.to_single_token(" London")
logit_diff = logits[0, -1, answer] - logits[0, -1, wrong]
```

metric을 정해야 patching 결과가 해석된다.

### Task 4. Zero ablation

실험:

- 특정 attention head output을 0으로 만든다.
- 특정 MLP output을 0으로 만든다.
- logit diff 변화를 측정한다.

추천 hook:

- `blocks.{L}.attn.hook_result` 또는 `hook_z`
- `blocks.{L}.hook_mlp_out`
- `blocks.{L}.hook_resid_post`

질문:

- 어느 layer/head를 지웠을 때 정답 logit이 가장 많이 떨어지는가?
- attention head와 MLP 중 어디가 더 큰 영향을 주는가?

완료 기준:

- [ ] layer별 ablation bar plot
- [ ] head별 ablation heatmap
- [ ] 결과 해석 10줄

### Task 5. Activation patching

패턴:

1. clean prompt와 corrupt prompt를 만든다.
2. clean run의 cache를 저장한다.
3. corrupt run 중 특정 activation만 clean activation으로 교체한다.
4. metric이 얼마나 복구되는지 본다.

예시 prompt:

```text
clean:   After John and Mary went to the store, Mary gave a bottle of milk to
corrupt: After John and Mary went to the store, John gave a bottle of milk to
answer candidates: John / Mary
```

완료 기준:

- [ ] layer x position patching heatmap
- [ ] 가장 중요한 layer/position 후보 3개
- [ ] 그 후보를 다시 ablation해서 교차 검증

---

## Phase 3 — Canonical circuits 재현

### Track A. Induction heads

개념:

- 반복된 패턴 `A B ... A`에서 다음 token `B`를 예측하는 head
- in-context learning의 작은 원형으로 자주 설명됨

실험:

- repeated token sequence 만들기
- attention pattern에서 previous occurrence를 보는 head 찾기
- head ablation으로 copy behavior 감소 확인

완료 기준:

- [ ] induction score 계산
- [ ] induction head 후보 list
- [ ] 후보 head ablation 결과

### Track B. IOI / Name mover style behavior

개념:

- Indirect Object Identification 류 task에서 이름 token을 옮기는 head 분석
- 너무 깊게 들어가기 전에 작은 재현만 목표

실험:

- clean/corrupt pair 생성
- answer token logit diff
- path patching 또는 activation patching

완료 기준:

- [ ] 하나의 prompt family에서 layer/head 중요도 heatmap
- [ ] “이 head가 name mover라고 말하려면 추가로 무엇이 필요할까?” 적기

---

## Phase 4 — SAE/Feature interpretability 입문

SAE는 초반부터 깊게 파면 도구 설치/대형 모델/feature cherry-picking에 빠지기 쉽다. Phase 1~3을 먼저 끝내고 들어간다.

해야 할 것:

1. pretrained SAE를 불러온다.
2. activation을 SAE feature로 encode한다.
3. feature별 top activating examples를 본다.
4. feature ablation 또는 steering으로 causal effect를 확인한다.

완료 기준:

- [ ] feature 하나에 대해 top examples 20개
- [ ] feature 설명 가설 1개
- [ ] activation intervention 결과
- [ ] “이 feature 해석이 왜 틀릴 수 있는지” 반례 3개

---

## 논문 읽기 순서

논문은 아래 순서로 “실험 후 읽기”를 추천한다.

1. Transformer Circuits thread / A Mathematical Framework for Transformer Circuits
2. In-context Learning and Induction Heads
3. IOI / causal tracing / path patching 관련 글
4. Toy Models of Superposition
5. Towards Monosemanticity
6. Sparse Autoencoders / feature circuits 관련 최신 글

읽을 때마다 아래만 뽑는다.

- 이 논문의 central claim은 무엇인가?
- 어떤 metric으로 증명했나?
- 어떤 intervention이 causal evidence인가?
- 내가 작은 모델에서 재현할 수 있는 최소 실험은 무엇인가?

## 흔한 함정

- attention map만 보고 해석했다고 착각함
- 예쁜 feature 이름 붙이고 causal test를 안 함
- prompt 하나에서만 본 결과를 일반화함
- clean/corrupt prompt가 token length/tokenization이 달라 patching이 깨짐
- metric 없이 “좋아진 것 같다”고 말함

## 매 실험 체크리스트

- [ ] clean/corrupt prompt가 token length를 맞추는가?
- [ ] answer token이 single token인가?
- [ ] metric이 scalar로 정의됐는가?
- [ ] baseline clean/corrupt score가 충분히 차이나는가?
- [ ] intervention 결과를 plot으로 남겼는가?
- [ ] 실패한 결과도 기록했는가?
