import sys
import math
input=sys.stdin.readline
def modinv(a,m):
    b=m
    u=1
    v=0
    while b:
        t=a//b
        a-=t*b
        a,b=b,a
        u-=t*v
        u,v=v,u
    u%=m
    if u<0:
        u+=m
    return u
a=int(input())
b=int(input())
c=int(input())
d=int(input())
e=int(input())
fr=a<0
ans=0
while a<b:
    if a<0:
        a+=1
        ans+=c
    elif a==0 and fr:
        ans+=d
        fr=False
    else:
        ans+=e
        a+=1
print(ans)
