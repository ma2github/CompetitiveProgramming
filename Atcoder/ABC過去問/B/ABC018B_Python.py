s=input()
n=int(input())
for _ in range(n):
    l,r=map(int,input().split())
    m=s[r-1:l-2:-1] if l>1 else s[r-1::-1]
    s=s[:l-1]+m+s[r:]
print(s)
