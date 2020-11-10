a=[list(map(int,input().split())) for _ in range(5)]
for i in range(5):
    if 1 in a[i]:
        print(abs(i-2)+abs(a[i].index(1)-2))
