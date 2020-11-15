a,b=map(int,input().split())
mx=max(a,b)
mn=min(a,b)
ans=0
for  _ in range(2):
    ans+=max(mx,mn)
    mx-=1
print(ans)    
