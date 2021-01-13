n,x=map(int,input().split())
s=input()
for c in s:
    x=max(0,x-(c=='x'))
    x+=c=='o'
print(x)
