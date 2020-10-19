def main():
    n,m=map(int,input().split())
    a=[input() for _ in range(n)]
    b=[input() for _ in range(m)]
    for i in range(n-m+1):
        for j in range(n-m+1):
            if [a[i+k][j:j+m] for k in range(m)]==b:
                    print('Yes')
                    return
    print('No')
main()
