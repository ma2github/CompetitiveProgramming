def main():
    s=input()
    len1=0
    len2=0
    ans=0
    for i in range(len(s)):
        if s[i]=='(':
            len1+=1
        if s[i]=='[':
            len2+=1
        if len1 and s[i]==')':
            ans+=1
            len1-=1
        if len2 and s[i]==']':
            ans+=1
            len2-=1
    print(ans)
tt=int(input())
for _ in range(tt):
    main()
