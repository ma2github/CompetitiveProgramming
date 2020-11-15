n,t=map(int,input().split())
ans=10**10
for _ in range(n):
    ci,ti=map(int,input().split())
    if ti<=t:
        ans=min(ans,ci)
print('TLE' if ans==10**10 else ans)
