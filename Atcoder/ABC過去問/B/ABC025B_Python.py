n,a,b=map(int,input().split())
ans=0
for _ in range(n):
    s,d=input().split()
    d=int(d)
    if s=='West':
        ans+=min(b,max(a,d))
    else:
        ans-=min(b,max(a,d))
if ans<0:
    print('East',-ans)
elif ans==0:
    print(0)
else:
    print('West',ans)
