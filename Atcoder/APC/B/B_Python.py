n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if sum(a)>sum(b):
    print('No')
    exit()
mod=0
c=[]
for i in range(n):
    if a[i]>b[i]:
        mod+=a[i]-b[i]
    elif b[i]>a[i]:
        c.append(b[i]-a[i])
for x in c:
    mod-=x//2
print('YNeos'[mod>0::2])
