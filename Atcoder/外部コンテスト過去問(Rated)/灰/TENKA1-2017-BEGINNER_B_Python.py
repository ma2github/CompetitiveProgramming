n=int(input())
amax=0
ans=0
for _ in range(n):
    a,b=map(int,input().split())
    if a>amax:
        ans=a+b
        amax=a
print(ans)
