n,x=map(int,input().split())
l=list(map(int,input().split()))
di=0
ans=0
while di<=x and ans<n:
    di=di+l[ans]
    ans+=1
if di<=x:
    ans+=1
print(ans)
