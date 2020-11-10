ok='CODEFESTIVAL2016'
s=input()
ans=0
for i in range(16):
    ans+=ok[i]!=s[i]
print(ans)
