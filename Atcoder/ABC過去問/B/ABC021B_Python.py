n=int(input())
p=list(map(int,input().split()))
k=int(input())
p+=list(map(int,input().split()))
p=set(p)
if len(p)==k+2:
    print('YES')
else:
    print('NO')
