# 05. Resources

## Mechanistic Interpretability

### 먼저 볼 것

1. **TransformerLens documentation**
   - TransformerLens API, hooks, cache, activation patching을 익히는 데 최우선.
   - https://transformerlensorg.github.io/TransformerLens/

2. **ARENA / Mechanistic Interpretability materials**
   - 실습 중심 자료. TransformerLens와 회로 분석에 좋음.
   - https://arena-chapter1-transformer-interp.streamlit.app/

3. **Neel Nanda — 200 Concrete Open Problems in Mechanistic Interpretability**
   - 연구 감각과 프로젝트 아이디어 참고.
   - https://www.alignmentforum.org/posts/LbrPTJ4fmABEdEnLf/200-cop-in-mi-interpretable-algorithms?

4. **Distill / Transformer Circuits thread**
   - 핵심 개념의 원류.
   - https://transformer-circuits.pub/

### 핵심 논문/글

- A Mathematical Framework for Transformer Circuits
- In-context Learning and Induction Heads
- A Mechanistic Interpretability Analysis of Grokking
- Toy Models of Superposition
- Towards Monosemanticity
- Sparse Autoencoders Find Highly Interpretable Features in Language Models

### 도구

- TransformerLens: hooks/cache/patching
- SAELens: sparse autoencoder feature 분석
- circuitsvis: attention/activation 시각화
- PyTorch: tensor 조작
- Jupyter: 실험 노트

### 읽는 법

논문을 읽을 때 전부 이해하려 하지 말고 아래만 뽑는다.

```md
## Paper note

- Claim:
- Model/task:
- Metric:
- Intervention:
- Main figure:
- What can I reproduce in 2 hours?:
- What did I not understand?:
```

## Binary Reversing

### 먼저 볼 것

1. **OpenSecurityTraining2**
   - architecture, x86/x64, reversing 기초 강의.
   - https://ost2.fyi/

2. **pwn.college**
   - systems/security 실습 환경. reversing뿐 아니라 low-level 감각에 좋음.
   - https://pwn.college/

3. **Ghidra tutorials / docs**
   - decompiler와 분석 workflow 익히기.
   - https://ghidra-sre.org/

4. **crackmes.one**
   - 초급 crackme 실습.
   - https://crackmes.one/

5. **Microcorruption**
   - embedded reversing 게임형 실습.
   - https://microcorruption.com/

### 나중에 볼 것

- RPISEC Modern Binary Exploitation
- Practical Malware Analysis
- The Art of 64-Bit Assembly
- Computer Systems: A Programmer's Perspective

## 공통적으로 도움이 되는 기초

### Systems

- C pointer/string/memory
- stack/heap
- calling convention
- process memory layout
- instruction set basics

### ML

- transformer architecture
- logits/probabilities/loss
- linear algebra/tensor shape
- PyTorch autograd 없이 forward pass 읽기

### 글쓰기

- 모든 실험은 README/writeup으로 남긴다.
- 그림 1개 + 표 1개 + 실패/한계 1개가 있으면 글 품질이 올라간다.

## 추천 루틴

### 평일 60~90분

- 10분: 지난 노트 읽기
- 40분: 실험/문제풀이
- 20분: writeup 정리
- 10분: 다음 액션 1개 적기

### 주말 3~4시간

- 2시간: notebook 또는 crackme 집중
- 1시간: 결과 정리
- 30분: 관련 글/논문 읽기
- 30분: 다음 주 계획

## 자료를 고르는 기준

좋은 자료:

- 코드/실습이 있다.
- 작은 모델/작은 binary로 시작한다.
- metric과 evidence를 강조한다.
- 실패 케이스를 설명한다.

나쁜 자료:

- 고수용 용어만 많고 실습이 없다.
- attention heatmap만 보여주고 causal test가 없다.
- crackme 정답만 던지고 분석 과정이 없다.
- 최신 논문 링크만 많고 입문 경로가 없다.
