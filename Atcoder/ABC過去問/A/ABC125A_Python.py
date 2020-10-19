a,b,t=map(int,input().split())
now=0
ans=0
while now+a<=t+0.5:
    now+=a
    ans+=b
print(ans)
