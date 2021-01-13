s=input()
t=s.replace('x','')
if t!=t[::-1]:
    print(-1)
else:
    ans=0
    l=0
    r=len(s)-1
    while l<r:
        if s[l]=='x' and s[r]!='x':
            l+=1
            ans+=1
        elif s[l]!='x' and s[r]=='x':
            r-=1
            ans+=1
        else:
            l+=1
            r-=1
    print(ans)
