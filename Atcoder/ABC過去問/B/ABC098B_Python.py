n=int(input())
s=input()
ans=0
for i in range(n):
    t=s[0:i]
    u=s[i:]
    ans=max(ans,len(set(t)&set(u)))
print(ans)
