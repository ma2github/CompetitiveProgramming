s=input()
ok='1234567890'
ans=''
for c in s:
    if c in ok:
        ans+=c

print(ans)
