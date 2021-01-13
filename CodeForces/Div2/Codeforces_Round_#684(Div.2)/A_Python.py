t=int(input())
for _ in range(t):
    n,c0,c1,h=map(int,input().split())
    s=input()
    ans=0
    zcnt=s.count('0')
    for c in s:
        ans+=(c=='0')*c0+(c=='1')*c1
    print(min(ans,c0*n+(n-zcnt)*h,c1*n+zcnt*h))
