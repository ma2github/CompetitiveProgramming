n=int(input())
ans=0
acnt=0
bcnt=0
bacnt=1
for _ in range(n):
    s=input()
    ans+=s.count('AB')
    acnt+=s[-1]=='A'
    bcnt+=s[0]=='B'
    if acnt!=bcnt:bacnt=0
ans+=min(acnt,bcnt)
ans-=bacnt
if (acnt==0 or bcnt==0) and bacnt:ans+=1
print(ans)
