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
class FlightPlan():
    def fly(self,a,b):
        return 'Yes' if max(a,b)<min(a,b)+3 else 'No'
main=FlightPlan()
tt=1
for _ in range(tt):
    #n,k=map(int,input().split())
    print(main.fly(*map(int,input().split())))
    #print(' '.join(main.solve(n,k,r)))
