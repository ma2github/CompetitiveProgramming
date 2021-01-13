s=input()
k=int(input())
ssort=sorted(list(s))
cold=ssort[0]
substr=[]
index=[-1]*26
for c in ssort:
    if cold!=c and len(substr)>=k:
        substr=sorted(substr)
        print(substr[k-1])
        exit()
    idx=index[ord(c)-97]+1
    idx1=s[idx:].index(c)+idx
    str=''
    for i in range(idx1,len(s)):
        str+=s[i]
        if len(str)>k:break
        if str in substr:continue
        substr.append(str)
    index[ord(c)-97]=idx1
    cold=c
substr=sorted(substr)
print(substr[k-1])
