s=input()
ans=0
i=0
cold=s[0]
while i<len(s):
    while cold==s[i]:
        i+=1
        if i==len(s):break
    index=i if i<len(s) else i-1
    ans+=cold!=s[index]
    cold=s[index]
print(ans)
