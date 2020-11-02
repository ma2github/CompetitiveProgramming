n=int(input())
ans=10000
for a in range(1,n//2+1):
    b=n-a
    ans=min(ans,sum(list(map(int,list(str(a)))))+sum(list(map(int,list(str(b))))))
print(ans)
