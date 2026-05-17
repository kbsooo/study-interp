# 001. Simple String Check

## Goal

작은 C 프로그램이 binary에서 어떻게 보이는지 확인한다.

## Source

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    if (strcmp(argv[1], "secret") == 0) {
        puts("correct");
    } else {
        puts("wrong");
    }
}
```

## Build

```bash
clang -O0 -g check.c -o check_O0
clang -O2 check.c -o check_O2
```

## Static observations

```bash
file check_O0
strings check_O0
otool -tV check_O0
```

적을 것:

- Format:
- Architecture:
- Interesting strings:
- Imported functions:
- Where is `strcmp` called?:

## Dynamic observations

```lldb
lldb ./check_O0
(lldb) breakpoint set --name main
(lldb) run test
(lldb) disassemble --frame
(lldb) register read
(lldb) thread step-inst
```

적을 것:

- argv[1] address:
- compare call location:
- branch after compare:
- register containing return value:

## Recovered pseudo-code

```c
if (argc != 2) return 1;
if (strcmp(argv[1], "secret") == 0) puts("correct");
else puts("wrong");
```

## What I learned

- 
