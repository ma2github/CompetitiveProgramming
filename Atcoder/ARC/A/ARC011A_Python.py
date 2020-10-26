m,n,N=map(int,input().split())
cnt=N
mod=0
while N>=m:
    cnt+=(N//m)*n
    N=(N//m)*n+N%m
print(cnt)
