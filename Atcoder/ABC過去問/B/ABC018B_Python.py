s=input()
n=int(input())
for _ in range(n):
    print(s)
    l,r=map(int,input().split())
    l-=1
    r-=1
    if l:
        s=s[:l]+s[r:l-1:-1]+s[r+1:]
    else:
        s=s[:l]+s[r::-1]+s[r+1:]
print(s)
