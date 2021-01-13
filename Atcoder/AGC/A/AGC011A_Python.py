n,c,k=map(int,input().split())
t=[int(input()) for _ in range(n)]
t.sort()
ans=0
ok=-1
cnt=0
for ti in t:
    if ok<ti or cnt==c:
        ans+=1
        ok=ti+k
        cnt=0
    cnt+=1
print(ans)
