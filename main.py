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
        ans=0
        def f(x):
            if x==0:
                return 0
            fa=0
            shift=0
            while (1<<shift)<=x:
                if shift==0:
                    if x%4==1 or x%4==2:
                        fa^=1
                elif (x%(1<<shift))&1==0 and (x>>shift)&1:
                    fa^=1<<shift
                shift+=1
            return fa
        return f(a-1)^f(b)
main=FlightPlan()
tt=1
for _ in range(tt):
    print(main.fly(*map(int,input().split())))
    #print(' '.join(main.solve(n,k,r)))
