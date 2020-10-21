n=int(input())
ans='atcoder'
sum=0
p=[0]*n
s=[""]*n
for i in range(n):
    s[i],p[i]=input().split()
    p[i]=int(p[i])
    sum+=p[i]
for i in range(n):
    if p[i]*2>sum:
        ans=s[i]
print(ans)
