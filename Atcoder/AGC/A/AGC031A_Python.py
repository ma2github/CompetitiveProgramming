MOD=10**9+7
n=int(input())
s=input()
ans=pow(2,n,MOD)-1
cnt=[0]*26
al='abcdefghijklmnopqrstuvwxyz'
for c in s:
    cnt[al.index(c)]+=1
md=n
cur=1
for x in cnt:
    md-=x
    ans-=(((pow(2,x,MOD)-(x+1)%MOD)*pow(2,md,MOD))%MOD)*cur%MOD
    ans%=MOD
    cur*=x+1
    cur%=MOD
print(ans%MOD)
