m,d=map(int,input().split())
ans=0
for d10 in range(2,d//10+1):
    for d1 in range(2,10):
        if d10*10+d1>d:
            break
        ans+=d1*d10<=m
print(ans)
