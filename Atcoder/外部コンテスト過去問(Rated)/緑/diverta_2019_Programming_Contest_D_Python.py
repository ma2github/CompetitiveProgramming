n=int(input())
ans=0
i=1
while i*i<n:
    if n%i==0 and (n//i)-1>i:
        ans+=(n//i)-1
    i+=1
print(ans)
