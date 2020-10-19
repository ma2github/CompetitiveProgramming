n=int(input())
s=0
m=n
while n:
    s+=n%10
    n=n//10
if m%s==0:
    print('Yes')
else:
    print('No')
