s=input()
ans=0
bccnt=0
i=len(s)-1
while i>=0:
    if s[i:i-2:-1]=='CB':
        bccnt+=1
        i-=1
    elif s[i]=='A':
        ans+=bccnt
    else:
        bccnt=0
    i-=1
print(ans)
