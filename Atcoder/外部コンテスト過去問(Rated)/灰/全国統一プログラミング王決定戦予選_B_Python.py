n=int(input())
a=input()
b=input()
c=input()
ans=0
for i in range(n):
    ans+=max(0,2-(a[i]==b[i])-(b[i]==c[i])-(c[i]==a[i]))
print(ans)
