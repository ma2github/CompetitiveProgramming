alp='abcdefghijklmnopqrstuvwxyz'.upper()
n=int(input())
s=input()
ans=''
for c in s:
    ans+=alp[(alp.index(c)+n)%26]
print(ans)
