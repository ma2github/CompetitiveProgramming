c=[input() for _ in range(4)]
ans=['....']*4
for i in range(4):
    ans[i]=c[3-i][7::-1]
for ansi in ans:
    print(ansi)
