n=int(input())
cnt=[0]*5
ok=list('MARCH')
ans=0
for _ in range(n):
    s=input()
    for i in range(5):
        cnt[i]+=s[0]==ok[i]
for i in range(1<<5):
    if str(bin(i)).count('1')!=3:
        continue
    can=1
    for j in range(5):
        if (i>>j)&1:
            can*=cnt[j]
    ans+=can
print(ans)
