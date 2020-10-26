a,k=map(int,input().split())
if k==0:
    print(2000000000000-a)
    exit(0)
cnt=0
while True:
    if a>=2000000000000:
        print(cnt)
        exit(0)
    a=a+1+k*a
    cnt+=1
