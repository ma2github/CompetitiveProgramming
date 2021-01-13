N=int(input())
for h in range((N+3)//4,3501):
    for n in range(1,3501):
        if (4*h*n-N*n-N*h)<=0:continue
        if (N*h*n)%(4*h*n-N*n-N*h)==0:
            print(h,n,(N*h*n)//(4*h*n-N*n-N*h))
            exit()
