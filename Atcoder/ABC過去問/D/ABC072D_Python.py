n=int(input())
p=list(map(int,input().split()))
ans=0
i=0
while i<n:
    if p[i]==i+1:
        ans+=1
        i+=p[i:i+2]==[i+1,i+2]
    i+=1
print(int(ans))
