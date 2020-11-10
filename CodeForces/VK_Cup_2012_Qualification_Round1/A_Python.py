n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
ans=0
for ai in set(a[-k::]):
    if ai==0:
        continue
    ans+=a.count(ai)
print(ans)
