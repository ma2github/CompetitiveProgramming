n=int(input())
d=list(map(int,input().split()))
d.sort()
m=int(input())
t=list(map(int,input().split()))
t.sort()
index=0
for ti in t:
    while index<n and d[index]<ti:
        index+=1
    if index<0 or d[index]!=ti:
        print('NO')
        exit()
    index+=1
print('YES')
