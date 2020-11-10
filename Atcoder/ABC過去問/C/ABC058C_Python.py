n=int(input())
s=[input() for _ in range(n)]
ok='abcdefghijklmnopqrstuvwxyz'
cnt=[60]*26
ans=''
for si in s:
    for c in ok:
        cnt[ok.index(c)]=min(cnt[ok.index(c)],si.count(c))
for c in ok:
    ans+=c*cnt[ok.index(c)]
print(ans)
