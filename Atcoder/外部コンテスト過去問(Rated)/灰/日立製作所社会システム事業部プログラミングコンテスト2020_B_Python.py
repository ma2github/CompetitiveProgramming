a,b,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ans=min(a)+min(b)
for _ in range(m):
    x,y,c=map(int,input().split())
    x-=1
    y-=1
    ans=min(ans,a[x]+b[y]-c)
print(ans)
