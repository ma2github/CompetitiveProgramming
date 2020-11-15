n=int(input())
s=input()
ans=10**10
sm1=[0]*(n+1)
sm2=[0]*(n+1)
for i in range(n):
    sm1[i+1]=sm1[i]+(s[i]=='#')
for i in range(-1,-(n+1),-1):
    sm2[n+i]=sm2[n+i+1]+(s[i]=='.')
for i in range(n+1):
    ans=min(ans,sm1[i]+sm2[i])
print(ans)
