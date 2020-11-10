n=int(input())
a=list(map(int,input().split()))
sm=[0]*(n+1)
cur=[0]*(n+1)
for i in range(n):
    sm[i+1]=sm[i]+a[i]
    cur[i+1]=cur[i]+sm[i+1]
ans=cur[n]
maxsm=sm[0]
for i in range(n):
    ans=max(ans,cur[i]+maxsm)
    maxsm=max(maxsm,sm[i+1])
print(ans)
