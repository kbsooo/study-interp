# Interp Study Command Center

> 목표: **mechanistic interpretability를 “논문 읽기”가 아니라 직접 실험하는 능력**으로 만들고, 병렬로 **binary reversing을 낮은 수준의 프로그램 이해/분해 능력**으로 쌓는다. 둘 다 공통적으로 “블랙박스를 내부 상태와 실행 경로로 설명하는 기술”이다.

## 지금 이 폴더의 역할

이 repo는 강의 북마크 모음이 아니라, 매주 산출물을 남기는 작업 공간이다.

```text
interp/
├── README.md                         # 현재 파일: 전체 대시보드
├── lecture-notebooks/                # 강의자료형 노트북
│   ├── 00-course-overview.ipynb       # 코스 목차/운영 방식
│   ├── 01-transformerlens-lecture-lab.ipynb
│   └── 02-binary-reversing-lecture-lab.ipynb
├── mech-interp/
│   └── transformerlens.ipynb          # 이미 시작한 TransformerLens 실험
└── docs/
    ├── 00-orientation.md              # 큰 그림, 선행지식, 공부법
    ├── 01-mech-interp-roadmap.md      # mech interp 상세 로드맵
    ├── 02-binary-reversing-roadmap.md # binary reversing 상세 로드맵
    ├── 03-weekly-sprints.md           # 8주 스프린트 플랜
    ├── 04-projects.md                 # 포트폴리오용 프로젝트 후보
    └── 05-resources.md                # 자료/강의/도구 링크
```

## 먼저 할 일: 오늘 2~3시간 루틴

1. `lecture-notebooks/00-course-overview.ipynb`를 열어 전체 흐름을 본다.
2. `lecture-notebooks/01-transformerlens-lecture-lab.ipynb`를 강의 듣듯이 위에서 아래로 실행한다.
3. 기존 `mech-interp/transformerlens.ipynb`를 강의 노트북 스타일로 정리한다.
4. 시간이 남으면 `lecture-notebooks/02-binary-reversing-lecture-lab.ipynb`를 실행한다.
5. 결과를 `notes/YYYY-MM-DD.md` 또는 `notes/week-01.md`에 10줄로 적는다.

## Definition of Mastery

### Mechanistic Interpretability

- [ ] GPT-2 small 또는 TinyStories 모델에서 tokenization, logits, residual stream, attention pattern, MLP activation을 직접 꺼내 설명할 수 있다.
- [ ] clean/corrupt prompt를 만들고 activation patching으로 특정 layer/head/position의 causal effect를 측정할 수 있다.
- [ ] induction head, name mover head, IOI-style behavior 중 하나를 작은 모델에서 재현한다.
- [ ] SAE/sparse feature를 “멋있어 보이는 그림”이 아니라 feature activation → examples → intervention으로 검증한다.
- [ ] 실험 하나를 notebook + README + 짧은 글로 남긴다.

### Binary Reversing

- [ ] C 코드가 컴파일되면 assembly/control flow/stack frame에서 어떻게 보이는지 설명할 수 있다.
- [ ] `strings`, `file`, `objdump`, `lldb`, Ghidra/IDA류 도구를 상황별로 쓴다.
- [ ] crackme 10개 이상을 풀고, 각 문제의 핵심 check routine을 pseudo-code로 복원한다.
- [ ] 동적 디버깅으로 breakpoint/register/memory를 보고 조건 분기를 우회하거나 입력을 복원한다.
- [ ] reversing writeup을 “도구 캡처”가 아니라 사고 과정 중심으로 쓴다.

## 추천 진행 방식

- **Mech interp는 notebook 중심**: 항상 “가설 → hook/patch → metric → 그래프 → 해석”으로 남긴다.
- **Reversing은 writeup 중심**: 항상 “관찰 → 정적 분석 → 동적 검증 → exploit/answer → 배운 패턴”으로 남긴다.
- 둘을 섞는 프로젝트는 나중에 한다. 초반에는 서로 다른 근육을 각각 키우는 게 낫다.

## 이번 주 최소 산출물

- [ ] `mech-interp/transformerlens.ipynb` 정리: 각 cell 위에 “이 실험이 뭘 검증하는지” markdown 추가
- [ ] `notes/week-01.md` 작성
- [ ] activation patching metric 하나 직접 정의
- [ ] crackme 1개 풀고 `reversing/writeups/001-*.md` 작성

## 문서 바로가기

- [00 Course Overview Notebook](lecture-notebooks/00-course-overview.ipynb)
- [01 TransformerLens Lecture Lab](lecture-notebooks/01-transformerlens-lecture-lab.ipynb)
- [02 Binary Reversing Lecture Lab](lecture-notebooks/02-binary-reversing-lecture-lab.ipynb)
- [00 Orientation](docs/00-orientation.md)
- [01 Mech Interp Roadmap](docs/01-mech-interp-roadmap.md)
- [02 Binary Reversing Roadmap](docs/02-binary-reversing-roadmap.md)
- [03 Weekly Sprints](docs/03-weekly-sprints.md)
- [04 Projects](docs/04-projects.md)
- [05 Resources](docs/05-resources.md)
