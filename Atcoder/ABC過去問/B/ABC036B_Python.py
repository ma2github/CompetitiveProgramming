n=int(input())
s=[input() for _ in range(n)]
ans=[""]*n
for i in range(n):
    for j in range(n):
        ans[i]+=s[n-1-j][i]
for ansi in ans:
    print(ansi)
