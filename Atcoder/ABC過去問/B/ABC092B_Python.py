n=int(input())
d,x=map(int,input().split())
for i in range(n):
    ai=int(input())
    cur=1
    while cur<=d:
        x+=1
        cur+=ai
print(x)
