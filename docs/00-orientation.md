# 00. Orientation: 왜 Mech Interp와 Binary Reversing을 같이 보나

## 한 줄 요약

둘 다 **관찰 가능한 입출력만 보지 않고, 내부 표현/상태/제어 흐름을 복원해서 시스템을 설명하는 기술**이다.

- Mech interp: neural network의 내부 activation, circuit, feature, causal path를 분석한다.
- Binary reversing: 컴파일된 프로그램의 assembly, memory, control flow, data flow를 분석한다.

다만 초반에는 섞지 말고 따로 훈련해야 한다. 공통 감각은 비슷하지만 도구와 수학/시스템 지식이 다르다.

## 북극성 목표

> “나는 모델/바이너리를 그냥 돌려보는 사람이 아니라, 내부에서 어떤 경로로 결론이 나오는지 실험으로 좁혀갈 수 있다.”

## 두 분야의 대응 관계

| 관점 | Mech Interp | Binary Reversing |
|---|---|---|
| 대상 | Transformer/NN | ELF/Mach-O/PE binary |
| 내부 상태 | residual stream, attention, MLP activations | registers, stack, heap, memory |
| 실행 단위 | layer/head/neuron/feature | instruction/basic block/function |
| 분석 도구 | TransformerLens, hooks, patching, SAE | Ghidra, objdump, lldb/gdb, radare2 |
| 핵심 질문 | 어떤 내부 표현이 출력에 causal하게 기여했나? | 이 프로그램이 어떤 조건에서 어떤 경로로 가나? |
| 산출물 | notebook, plots, causal metric, writeup | pseudo-code, CFG, patch/input, writeup |

## 공부 순서 원칙

### 1. “개념 이해”보다 “작은 재현”이 먼저

Mech interp는 논문만 읽으면 허공에 뜬다. 작은 모델에서 직접 다음을 해야 한다.

- prompt를 token으로 바꾸기
- logits에서 top-k prediction 보기
- attention pattern 시각화하기
- activation zero ablation하기
- clean/corrupt activation patching하기

Binary reversing도 강의만 보면 손에 안 남는다.

- 아주 작은 C 코드를 직접 컴파일한다.
- objdump/lldb로 본다.
- Ghidra로 pseudo-code를 본다.
- crackme를 풀고 writeup을 쓴다.

### 2. 매번 metric을 정한다

나쁜 mech interp 실험:

> “attention이 여기를 보는 것 같다.”

좋은 mech interp 실험:

> “clean prompt에서 정답 token logit diff가 +3.1이고, layer 7 position -1 residual을 corrupt run에 patch하면 +2.4까지 복구된다.”

나쁜 reversing writeup:

> “Ghidra를 보니까 답이 있었다.”

좋은 reversing writeup:

> “입력 문자열을 한 글자씩 XOR 0x37 후 테이블과 비교한다. lldb에서 compare 직전 메모리를 확인했고, 역연산으로 입력을 복원했다.”

### 3. 포트폴리오 기준으로 공부한다

AI Safety/Alignment 관점에서 강점이 되려면 그냥 “공부했다”보다 이런 산출물이 낫다.

- 작은 모델의 특정 behavior를 causal tracing으로 분석한 notebook
- SAE feature 하나를 찾고 examples/intervention으로 검증한 글
- toy binary를 분석하면서 static/dynamic analysis를 비교한 writeup
- “reversing 관점으로 neural circuit 분석을 설명하는” 메타 글

## 선행지식 체크리스트

### Python/PyTorch

- [ ] tensor shape를 보고 batch/position/d_model 축을 바로 구분한다.
- [ ] broadcasting/인덱싱을 헷갈리지 않는다.
- [ ] `torch.topk`, `softmax`, `log_softmax`, `einsum`을 읽을 수 있다.
- [ ] notebook에서 실험 결과를 재현 가능하게 정리한다.

### Transformer

- [ ] token embedding + positional embedding
- [ ] attention score/probability/value aggregation
- [ ] residual stream
- [ ] layer norm
- [ ] MLP block
- [ ] unembedding/logits

### Systems / Reversing

- [ ] C 함수, pointer, array, string, struct
- [ ] stack frame, calling convention
- [ ] register, memory address, endian
- [ ] branch/jump/call/ret
- [ ] static vs dynamic analysis

## 실험 노트 템플릿

`notes/YYYY-MM-DD.md`에 아래 형식으로 쓴다.

```md
# YYYY-MM-DD

## 오늘 한 것
- 

## 가설
- 

## 실험/분석
- 

## 관찰
- 

## 막힌 점
- 

## 다음 액션
- 
```

## 추천 폴더 구조

```text
interp/
├── mech-interp/
│   ├── transformerlens.ipynb
│   ├── ioi-patching.ipynb
│   ├── induction-heads.ipynb
│   └── sae-feature-audit.ipynb
├── reversing/
│   ├── labs/
│   ├── crackmes/
│   └── writeups/
├── notes/
└── docs/
```
