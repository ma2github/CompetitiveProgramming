def main():
    ans=0
    n=int(input())
    if n==1:
        ans=0
    elif n==2:
        ans=1
    elif n%2==0 or n==3:
        ans=2
    else:
        ans=3
    print(ans)
tt=int(input())
for _ in range(tt):
    main()
