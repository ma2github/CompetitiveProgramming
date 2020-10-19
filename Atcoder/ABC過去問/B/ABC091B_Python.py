n=int(input())
s=[input() for _ in range(n)]
m=int(input())
t=[input() for _ in range(m)]
ans=0
for str in s:
    ans=max(ans,s.count(str)-t.count(str))
print(ans)
