n=int(input())
a=list(map(int,input().split()))
cnt=0
for ai in a:
    cnt+=ai&1
print('YNEOS'[cnt&1::2])
