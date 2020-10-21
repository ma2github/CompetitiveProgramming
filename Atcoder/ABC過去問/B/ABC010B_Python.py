n=int(input())
a=list(map(int,input().split()))
ans=0
for ai in a:
    if ai%3==2:
        ans+=1+ai%2
    elif ai%2==0:
        ans+=1+2*(ai%3==0)
print(ans)
