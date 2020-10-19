n,m=map(int,input().split())
mn=[10**9]*n
ans=[0]*n
ab=[list(map(int,input().split())) for _ in range(n)]
cd=[list(map(int,input().split())) for _ in range(m)]
i=0
for aibi in ab:
    j=1
    for cjdj in cd:
        if abs(aibi[0]-cjdj[0])+abs(aibi[1]-cjdj[1])<mn[i]:
            mn[i]=abs(aibi[0]-cjdj[0])+abs(aibi[1]-cjdj[1])
            ans[i]=j
        j+=1
    i+=1
for ansi in ans:
    print(ansi)
