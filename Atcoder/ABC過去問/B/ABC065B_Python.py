n=int(input())
a=[int(input()) for _ in range(n)]
cnt=[0]*n
if 2 in a:
    cur=1
    while cur!=2 and cnt[cur-1]==0:
        cur-=1
        cnt[cur]=1
        cur=a[cur]
    if cur==2:
        print(cnt.count(1))
    else:
        print(-1)
else:
    print(-1)
