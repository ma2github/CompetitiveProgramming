#!/usr/bin/env python3
import random
n = random.randint(2, 2e5)
k = random.randint(1, 1e9)
print(n,k)
L=list(range(1,n+1))
random.shuffle(L)
L=[str(i) for i in L]
L=" ".join(L)
print(L)
C=[random.randint(-1e9,1e9) for i in range(n)]
C=[str(i) for i in C]
C=" ".join(C)
print(C)
