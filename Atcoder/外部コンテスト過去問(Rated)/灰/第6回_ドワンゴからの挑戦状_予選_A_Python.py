n=int(input())
sm=[0]*(n+1)
s=[""]*n
t=[0]*n
for i in range(n):
    s[i],t[i]=input().split()
    t[i]=int(t[i])
    sm[i+1]=sm[i]+t[i]
x=input()
print(sm[n]-sm[s.index(x)+1])
