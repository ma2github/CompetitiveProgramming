h,w=map(int,input().split())
c=[input() for _ in range(h)]
ans=[""]*(2*h)
for i in range(2*h):
    for j in range(w):
        ans[i]+=c[i//2][j]
for ansi in ans:
    print(ansi)
