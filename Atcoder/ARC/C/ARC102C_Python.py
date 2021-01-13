n,k=map(int,input().split())
ans=(n//k)*(n//k)*(n//k)
if k%2==0:
    ans+=((n+(k//2))//k)*((n+(k//2))//k)*((n+(k//2))//k)
print(ans)
