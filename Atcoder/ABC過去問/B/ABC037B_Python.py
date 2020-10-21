n,q=map(int,input().split())
ans=[0]*n
for _ in range(q):
    l,r,t=map(int,input().split())
    l-=1
    for i in range(l,r):
        ans[i]=t
for ansi in ans:
    print(ansi)
