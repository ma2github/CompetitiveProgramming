#!/usr/bin/env python3
import random
n = random.randint(1,16)
m = random.randint(0, n*(n-1)/2)
print(n,m)
for i in range(m):
    si = random.randint(1,n-1)
    ti = random.randint(si+1,n)
    di = random.randint(1,1e12)
    timei = random.randint(1,1e12)
    print(si,ti,di,timei)
