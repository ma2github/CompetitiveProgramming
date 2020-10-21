n,s,t=map(int,input().split())
w=int(input())
a=[int(input()) for _ in range(n-1)]
ans=w<=t and w>=s
for ai in a:
    w+=ai
    ans+=w<=t and w>=s
print(ans)
