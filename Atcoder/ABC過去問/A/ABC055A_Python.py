n=int(input())
ans=0
while n:
    ans+=800*min(15,n)
    if n>=15:
        ans-=200
    n-=min(15,n)
print(ans)
