def main():
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    lim=(n-1)*a[-1]
    ans=lim-sum(a)
    if ans<0:ans%=n-1
    print(ans)
tt=int(input())
for _ in range(tt):
    main()
