s,p=map(int,input().split())
i=1
while i*i<=p:
    if p%i==0 and i+p//i==s:
        print('Yes')
        exit()
    i+=1
print('No')
