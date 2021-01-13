def main():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    ans=0
    for i in range(k):
        ans+=a[-(((n+2)//2)*(i+1))]
        #print(a[-(((n+2)//2)*(i+1))])
    print(ans)

t=int(input())
for _ in range(t):
    main()
