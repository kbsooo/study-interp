# Week 01 Notes

## 이번 주 목표

TransformerLens 기본 실험을 “무슨 일이 일어나는지 설명 가능한 상태”로 만들고, 아주 작은 binary reversing lab 하나를 끝낸다.

## Mech Interp TODO

- [ ] `mech-interp/transformerlens.ipynb` 처음부터 재실행
- [ ] 각 cell 위에 목적/shape/해석 markdown 추가
- [ ] final token logits top-10 출력 정리
- [ ] cache key 10개와 shape 표 작성
- [ ] attention pattern 하나 저장
- [ ] zero ablation 전후 logit diff 표 작성

## Reversing TODO

- [ ] `reversing/labs/check.c` 작성
- [ ] `clang -O0 -g check.c -o check_O0`
- [ ] `clang -O2 check.c -o check_O2`
- [ ] `strings`, `otool`, `lldb`로 분석
- [ ] `reversing/writeups/001-simple-string-check.md` 작성

## 오늘 막히면 볼 질문

- 지금 보고 있는 tensor의 shape는 무엇인가?
- 이 실험의 metric은 무엇인가?
- 이 결과가 causal evidence인가, 단순 관찰인가?
- binary에서 입력은 어디서 읽히고 어디서 비교되는가?
- 정답을 찾은 게 아니라 로직을 복원했는가?
