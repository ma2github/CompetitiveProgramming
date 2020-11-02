n=int(input())
a=list(map(int,input().split()))
cnt=[-i for i in range(10**5+10)]
ans=0
for ai in a:
    if ai>n:
        ans+=1
        continue
    cnt[ai]+=1
for i in range(10**5):
    ans+=cnt[i] if cnt[i]>=0 else i+cnt[i]
print(ans)
