n=int(input())
a=list(map(int,input().split()))
index=1
f=1
g=0
ans=0
while index<n:
    if a[index]==a[index-1] and f:
        ans+=1
        f=0
        g=index
    index+=1
    if g+1<index:
        f=1
print(ans)
