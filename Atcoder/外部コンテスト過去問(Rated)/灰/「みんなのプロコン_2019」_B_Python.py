cnt=[0]*5
for _ in range(3):
    a,b=map(int,input().split())
    cnt[a]+=1
    cnt[b]+=1
print('YES' if cnt.count(1)==2 & cnt.count(2)==2 else 'NO')
