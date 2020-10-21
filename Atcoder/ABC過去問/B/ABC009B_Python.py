n=int(input())
a=list(set([int(input()) for _ in range(n)]))
a.sort()
print(a[len(a)-2])
