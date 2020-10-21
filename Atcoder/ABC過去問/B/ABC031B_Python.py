l,h=map(int,input().split())
n=int(input())
ans=[0]*n
for i in range(n):
    ai=int(input())
    ans[i]=max(-1,h-ai)
    if ans[i]!=-1:
        if ai<l:
            ans[i]=l-ai
        else:
            ans[i]=0
for ansi in ans:
    print(ansi)
