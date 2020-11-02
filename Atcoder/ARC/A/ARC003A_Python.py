n=int(input())
r=input()
ans=0
grade='FDCBA'
for c in r:
    ans+=grade.index(c)
ans/=n
print(ans)
