n=int(input())
ans=1
mx=0
for i in range(1,n+1):
    num=i
    res=0
    while num%2==0:
        res+=1
        num/=2
    if mx<res:
        mx=res
        ans=i
print(ans)
