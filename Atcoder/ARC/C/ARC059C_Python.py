n=int(input())
a=list(map(int,input().split()))
ans=10**10
for y in range(-100,101):
    cur=0
    for ai in a:
        cur+=(ai-y)*(ai-y)
    ans=min(ans,cur)
print(ans)
