#!/usr/bin/env python3
import random
"""
x = 1
k = 100000
d = random.randint(1,1e15)
print(1)
print(100000)
list=[str(1000000000) for _ in range(99999)]
list.append('1000000000')
L=' '.join(list)
print(L)
"""
tt=10**6
print(tt)
for _ in range(tt):
    print(random.randint(1<<62,1<<63),random.randint(1,10))
