a,b,x=map(int,input().split())
cur=1
d=1
while (a*cur)+(b*d)<=x:
    cur*=10
    d+=1
l=cur//10
r=cur
while abs(r-l)>1:
    mid=(r+l)//2
    if a*mid+b*(d-1)<=x:
        l=mid
    else:
        r=mid
print(min(l,10**9))
