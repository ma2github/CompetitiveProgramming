n=int(input())
k=int(input())
x=int(input())
y=int(input())
ans=0
while n:
    if k:
        ans+=x
        k-=1
    else:
        ans+=y
    n-=1
print(ans)
