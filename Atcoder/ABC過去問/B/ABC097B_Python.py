x=int(input())
ans=1
for i in range(2,x):
    res=i*i
    while res<=x:
        ans=max(ans,res)
        res*=i
print(ans)
