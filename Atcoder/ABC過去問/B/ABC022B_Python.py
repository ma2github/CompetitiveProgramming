n=int(input())
a=[int(input()) for _ in range(n)]
ok=[0]*(10**5+10)
ans=0
for ai in a:
    ans+=ok[ai]
    ok[ai]=1
print(ans)
