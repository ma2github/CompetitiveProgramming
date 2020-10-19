o=input()
e=input()
l=len(e)
ans=""
for i in range(l):
    ans+=o[i]+e[i]
if len(o)>l:
    ans+=o[len(o)-1]
print(ans)
