n=int(input())
ans=0
for _ in range(n):
    a=list(map(int,input().split()))
    ans+=a.count(1)>1
print(ans)
