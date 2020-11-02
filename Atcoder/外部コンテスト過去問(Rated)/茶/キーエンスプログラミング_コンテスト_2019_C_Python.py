n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if sum(a)<sum(b):
    print(-1)
else:
    ans=0
    c=[0]*n
    for i in range(n):
        ans+=b[i]>a[i]
        c[i]=a[i]-b[i]
    if ans==0:
        print(0)
    else:
        c.sort()
        r=n
        dlt=sum(c[:ans])+sum(c[r:])
        while dlt<0:
            r-=1
            dlt+=c[r]
        ans+=n-r
        print(ans)
