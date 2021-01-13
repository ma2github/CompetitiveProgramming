#高橋くんが食事iを食べるということは，ai+biだけのアドバンテージを得るということ
#-sum(b)からa+bの降順に(n+1)//2こたしてやれば良い
n=int(input())
a=[0]*n
b=[0]*n
ab=[0]*n
for i in range(n):
    a[i],b[i]=map(int,input().split())
    ab[i]=a[i]+b[i]
ab.sort()
ans=-sum(b)
f=1
for x in ab[::-1]:
    ans+=x*f
    f=1-f
print(ans)
