n=int(input())
a=list(map(int,input().split()))
d=max(a)
ans=0
for i in range(n):
    if d>abs(sum(a)-a[i]*n):
        ans=i
        d=abs(sum(a)-a[i]*n)
print(ans)
