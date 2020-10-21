n=int(input())
s=[input() for _ in range(n)]
mx=0
ans=''
for x in s:
    if mx<s.count(x):
        ans=x
        mx=s.count(x)
print(ans)
