s=input()
if len(s)==1:
    print('YES')
    exit()
alp='abcdefghijklmnopqrstuvwxyz'
cnt=[0]*26
for c in s:
    cnt[alp.index(c)]+=1
cur=''
nxt=0
l=0
while l<len(s):
    if cnt[nxt]:
        cur+=alp[nxt]
        l+=1
        cnt[nxt]-=1
    nxt+=1
    if len(cur)>2:
        cur=''
        nxt=0
    if nxt==26:
        print('NO')
        exit()
idx=0
print('YES')
