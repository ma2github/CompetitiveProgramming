n=int(input())
ans=n
for a in range(1,n+1):
    ans=min(ans,abs(a-n//a)+n%a)
print(ans)
