n=int(input())
x=list(map(int,input().split()))
l=sorted(x)
for xi in x:
    print(l[n//2] if xi<l[n//2] else l[n//2-1])
