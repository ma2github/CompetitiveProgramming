h,w,a,b=map(int,input().split())
ans=[str(1)*a+str(0)*(w-a)]*b+[str(0)*a+str(1)*(w-a)]*(h-b)
for x in ans:
    print(x)
