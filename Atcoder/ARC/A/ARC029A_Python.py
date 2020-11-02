n=int(input())
t=[int(input()) for _ in range(n)]
d=10000000
ans=sum(t)
for i in range(1<<n):
    cur=0
    for j in range(n):
        if (i>>j)&1:
            cur+=t[j]
    if abs(sum(t)-2*cur)<d:
        d=abs(sum(t)-2*cur)
        ans=max(cur,sum(t)-cur)
print(ans)
