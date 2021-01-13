def modinv(a,m):
    b=m
    u=1
    v=0
    while b:
        t=a//b
        a-=t*b
        a,b=b,a
        u-=t*v
        u,v=v,u
    u%=m
    return u
n=int(input())
MOD=998244353
dpsum=[0]*(n+1)
dp=1
for i in range(n):
    dpsum[i+1]=(dp+dpsum[i])%MOD
    dp=dpsum[i]%MOD
ans=dpsum[n]
div=modinv(2,MOD)
for _ in range(n):
    ans*=div
    ans%=MOD
print(ans)
