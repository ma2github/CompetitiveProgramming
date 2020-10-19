l=list(map(int,input().split()))
ans=0
for i in range(3):
    ans=max(ans,l[i]*9+sum(l))
print(ans)
