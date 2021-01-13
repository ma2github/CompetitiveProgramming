n,p=map(int,input().split())
a=list(map(int,input().split()))
ans=0
cnt=[0]*(((n+3)//4))
cnt0=[0]*(((n+3)//4))
for i in range((n+3)//4):
    for x in range(16):
        cur=0
        f=True
        for y in range(4):
            if (x>>y)&1:
                if  4*i+y>=n:
                    f=False
                    break
                cur+=a[4*i+y]
        if f:
            cnt[i]+=cur%2
            cnt0[i]+=1-cur%2
for i in range(1<<((n+3)//4)):
    if str(bin(i)).count('1')%2!=p:continue
    ret=1
    for j in range((n+3)//4):
        if (i>>j)&1:
            ret*=cnt[j]
        else:
            ret*=cnt0[j]
    ans+=ret
print(ans)
