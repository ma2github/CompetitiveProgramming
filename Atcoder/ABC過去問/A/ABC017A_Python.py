ans=0
for _ in range(3):
    s,t=map(int,input().split())
    ans+=s*t//10
print(ans)
