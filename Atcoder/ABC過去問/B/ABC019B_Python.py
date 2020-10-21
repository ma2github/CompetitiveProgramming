s=input()
ans=''
idx=0
while idx<len(s):
    cnt=1
    c=s[idx]
    if idx<len(s)-1:
        while s[idx]==s[idx+1]:
            cnt+=1
            idx+=1
            if idx==len(s)-1:
                break
    idx+=1
    ans+=c+str(cnt)
print(ans)
