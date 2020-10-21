def main():
    n=int(input())
    txy=[list(map(int,input().split())) for _ in range(n)]
    curt=0
    curx=0
    cury=0
    for [t,x,y] in txy:
        if abs(x-curx)+abs(y-cury)>t-curt:
            print('No')
            return
        if (abs(x-curx)+abs(y-cury)-(t-curt))%2:
            print('No')
            return
        curt=t
        curx=x
        cury=y
    print('Yes')
main()
