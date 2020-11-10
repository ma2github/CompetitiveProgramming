n=int(input())
x=0
y=0
z=0
for _ in range(n):
    xi,yi,zi=map(int,input().split())
    x+=xi
    y+=yi
    z+=zi
print('YNEOS'[(x or y or z)!=0::2])
