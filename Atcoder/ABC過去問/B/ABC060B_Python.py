a,b,c=map(int,input().split())
ok=[0]*b
now=a
while ok[now%b]==0:
    ok[now%b]=1
    now+=a
if ok[c]:
    print('YES')
else:
    print('NO')
