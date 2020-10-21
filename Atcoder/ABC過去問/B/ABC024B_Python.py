n,t=map(int,input().split())
a=[int(input()) for _ in range(n)]
ans=t
for i in range(n-1):
    ans+=min(t,a[i+1]-a[i])
print(ans)
