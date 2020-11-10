n=int(input())
i=1
ans=10
while i*i<=n:
    if n%i==0:
        ans=min(ans,len(str(n//i)))
    i+=1
print(ans)
