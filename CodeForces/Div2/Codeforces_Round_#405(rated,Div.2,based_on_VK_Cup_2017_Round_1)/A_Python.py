a,b=map(int,input().split())
ans=1
while a*(3**ans)<=b*(2**ans):ans+=1
print(ans)
