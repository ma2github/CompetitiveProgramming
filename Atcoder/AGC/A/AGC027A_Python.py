n,x=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
for i in range(n):
    if x-a[i]<0:
        print(i)
        exit()
    x-=a[i]
print(n-1 if x else n)
