r,g,b,n=map(int,input().split())
ans=0
for x in range(n+1):
    if r*x>n:
        break
    for y in range(n+1):
        if r*x+g*y>n:
            break
        ans+=(n-r*x-g*y)%b==0
print(ans)
