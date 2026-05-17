# 04. Portfolio Project Ideas

## Project 1 — GPT-2 Small에서 Activation Patching으로 특정 사실/문법 behavior 분석

### 질문

모델이 특정 prompt에서 정답 token을 고르는 데 어떤 layer/position activation이 causal하게 기여하는가?

### 예시 prompt

- factual: `The capital of France is`
- syntax: `The key to the cabinets is/are`
- name relation: IOI-style prompt

### 방법

1. clean/corrupt prompt pair 만들기
2. answer/wrong token 정하기
3. logit diff metric 정의
4. clean/corrupt baseline 측정
5. layer x position activation patching
6. top candidates ablation
7. 결과 해석

### 산출물

- notebook
- heatmap figures
- README/writeup

### 좋은 점

AI Safety/Alignment 포트폴리오에 직접 연결된다. “나는 논문만 읽은 게 아니라 causal intervention을 해봤다”는 신호가 된다.

## Project 2 — Attention Head가 진짜 중요한지 검증하기

### 질문

시각적으로 흥미로운 attention pattern을 보이는 head가 실제 출력에도 중요한가?

### 방법

1. attention pattern에서 흥미로운 head 후보 찾기
2. head ablation
3. patching 또는 direct logit attribution으로 검증
4. attention-only explanation의 한계 정리

### 산출물

- `head-ablation.ipynb`
- 글: “Attention pattern is a clue, not an explanation”

## Project 3 — Induction Head Mini Reproduction

### 질문

작은 모델에서 induction head 후보를 찾고, copy behavior에 causal하게 기여함을 보일 수 있는가?

### 방법

1. repeated token sequence dataset 생성
2. induction score 계산
3. 후보 head 찾기
4. 후보 head ablation
5. copy token logit 변화 측정

### 산출물

- notebook
- induction score heatmap
- ablation result table

## Project 4 — Crackme Pattern Zoo

### 질문

초급 crackme에서 반복되는 검증 패턴을 체계적으로 분류할 수 있는가?

### 패턴

- string compare
- reversed string
- XOR
- arithmetic transform
- lookup table
- checksum
- anti-debugging

### 산출물

- `reversing/writeups/`에 7개 writeup
- `reversing/solvers/`에 solver scripts
- 요약 글: “Crackme validation patterns for beginners”

## Project 5 — Static vs Dynamic Analysis 비교

### 질문

같은 binary를 Ghidra static analysis와 lldb dynamic analysis로 봤을 때 각각 무엇을 잘/못 보는가?

### 방법

1. 작은 crackme 2개 선택
2. static-only로 pseudo-code 복원
3. dynamic으로 register/memory 검증
4. 둘의 차이 정리

### 산출물

- writeup 2개
- 비교표

## Project 6 — Interp x Reversing 메타 글

### 제목 후보

- “Mechanistic Interpretability as Reverse Engineering Neural Programs”
- “Activation Patching and Dynamic Tracing: A Shared Mental Model”
- “Why Static Explanations Are Not Enough: Attention Maps and Decompiled Code”

### 핵심 논지

- attention map은 decompiled pseudo-code처럼 단서이지 증거가 아니다.
- causal intervention은 debugger에서 state를 바꿔보는 것과 비슷하다.
- model internals와 binary internals 모두 “실행 중 상태”를 봐야 한다.

### 산출물

- 블로그 글
- 그림 1~2개
- mech interp notebook / reversing writeup 링크

## 추천 우선순위

1. **Project 1**: AI Safety/Alignment 쪽 직접 관련성 높음
2. **Project 3**: canonical mech interp 재현이라 신뢰도 높음
3. **Project 4**: reversing 기본기를 보여줌
4. **Project 6**: 두 관심사를 하나의 관점으로 묶음

## 포트폴리오 품질 기준

좋은 프로젝트는 아래를 만족한다.

- 문제 정의가 명확하다.
- metric이 있다.
- 재현 가능한 코드가 있다.
- 실패/한계를 적는다.
- 그림이나 표가 있다.
- README만 봐도 뭘 했는지 이해된다.

나쁜 프로젝트:

- 링크 모음만 있음
- 논문 요약만 있음
- notebook은 있는데 결과 해석이 없음
- “이 head가 중요해 보인다”에서 멈춤
- reversing 정답만 있고 분석 과정이 없음
