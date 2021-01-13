n=int(input())
a=[int(input()) for _ in range(n)]
if n==2:
    print(abs(a[0]-a[1]))
    exit()
a.sort()
if n==3:
    print(max(2*a[2]-a[0]-a[1],a[2]+a[1]-2*a[0]))
    exit()
sm1=sum(a[:(n-2)//2+1:-1])
sm2=sum(a[:(n-2)//2])
sm3=sum(a[:(n-1)//2])
sm4=sum(a[:(n-1)//2+1:-1])
a1=a[(n-2)//2]
a2=a[(n-2)//2+1]
a3=a[(n-1)//2]
a4=a[(n-1)//2+1]
if n%2==0:
    a2=-a2
    a3=-a3
ans=max(2*(sm1-sm2)-(a1+a2),2*(sm4-sm3)+(a3+a4))
print(ans)
