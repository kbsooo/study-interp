# 03. 8-Week Sprint Plan

## 운영 규칙

- 매주 결과물 1개 이상.
- 논문/강의 소비 시간보다 실험/분석 시간이 많아야 한다.
- 실패도 산출물이다. 단, 왜 실패했는지 써야 한다.
- 주당 시간이 적으면 mech interp를 우선하고 reversing은 Lab 1개만 한다.

## Week 1 — Setup and First Causal Experiments

### Mech Interp

- [ ] `transformerlens.ipynb` 전체 재실행
- [ ] cache key/shape 표 만들기
- [ ] top-k logits 분석 cell 정리
- [ ] attention heatmap 1개 저장
- [ ] zero ablation으로 logit diff 변화 측정

산출물:

- `notes/week-01.md`
- `mech-interp/figures/attention-layer0-head0.png`
- notebook markdown 정리

### Reversing

- [ ] `check.c` 직접 작성
- [ ] O0/O2 컴파일
- [ ] `strings`, `otool/objdump`, `lldb`로 분석
- [ ] writeup 작성

산출물:

- `reversing/labs/check.c`
- `reversing/writeups/001-simple-string-check.md`

## Week 2 — Activation Patching / Basic Crackmes

### Mech Interp

- [ ] clean/corrupt prompt pair 3개 만들기
- [ ] answer token logit diff metric 작성
- [ ] layer x position activation patching heatmap 만들기
- [ ] 중요한 layer/position 후보 3개 기록

산출물:

- `mech-interp/activation-patching-basic.ipynb`
- `notes/week-02.md`

### Reversing

- [ ] plain string compare crackme 1개
- [ ] XOR constant crackme 1개
- [ ] Python solver 작성

산출물:

- `reversing/writeups/002-*.md`
- `reversing/solvers/002-*.py`

## Week 3 — Attention Heads / Debugging Fluency

### Mech Interp

- [ ] head별 ablation heatmap
- [ ] attention pattern과 ablation 결과 비교
- [ ] “attention map만으로는 부족한 예시” 하나 작성

산출물:

- `mech-interp/head-ablation.ipynb`

### Reversing

- [ ] lldb에서 breakpoint/register/memory 읽기 연습
- [ ] lookup table 또는 per-character arithmetic 문제 1개

산출물:

- `reversing/writeups/003-*.md`

## Week 4 — Induction Heads / Pattern Recognition

### Mech Interp

- [ ] repeated sequence prompt 생성
- [ ] induction score 계산
- [ ] induction head 후보 찾기
- [ ] 후보 head ablation

산출물:

- `mech-interp/induction-heads.ipynb`
- 짧은 글: “내가 찾은 induction head 후보와 evidence”

### Reversing

- [ ] checksum/hash-like validation 문제 1개
- [ ] solver로 brute force 또는 역연산

산출물:

- `reversing/writeups/004-*.md`

## Week 5 — IOI-style Causal Tracing / Control Flow

### Mech Interp

- [ ] IOI-style prompt family 만들기
- [ ] clean/corrupt baseline 확인
- [ ] layer/position patching
- [ ] name token 관련 후보 분석

산출물:

- `mech-interp/ioi-mini.ipynb`

### Reversing

- [ ] nested branch crackme
- [ ] CFG를 손으로 그림 또는 mermaid로 작성

산출물:

- `reversing/writeups/005-*.md`

## Week 6 — SAE 맛보기 / Anti-debugging 기초

### Mech Interp

- [ ] pretrained SAE 또는 작은 SAE 예제 실행
- [ ] feature top activating examples 보기
- [ ] feature 설명 가설 쓰기
- [ ] intervention 가능하면 시도

산출물:

- `mech-interp/sae-feature-audit.ipynb`

### Reversing

- [ ] 아주 쉬운 anti-debugging 문제
- [ ] 탐지 로직과 우회 방법 정리

산출물:

- `reversing/writeups/006-*.md`

## Week 7 — Portfolio Project 1

둘 중 하나 선택.

### Option A. Mech Interp writeup

- 특정 behavior 하나 선택
- metric 정의
- ablation/patching/visualization
- 결과 해석
- 한계와 반례

### Option B. Reversing writeup bundle

- crackme 5개를 패턴별로 묶어서 정리
- static vs dynamic analysis 비교
- solver scripts 포함

## Week 8 — Synthesis

최종 글 후보:

1. “Transformer activation patching을 binary dynamic tracing처럼 이해하기”
2. “Attention map이 explanation이 아닌 이유: reversing의 static analysis와 비교”
3. “작은 모델에서 causal evidence 만들기: logit diff, ablation, patching”
4. “Crackme 10개로 배운 control/data flow 복원 패턴”

완료 기준:

- [ ] public/private repo README 정리
- [ ] 대표 notebook 1개 clean run 가능
- [ ] writeup 2개 이상 완성
- [ ] 다음 8주 계획 초안 작성
