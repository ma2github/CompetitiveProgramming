n=int(input())
a=list(map(int,input().split()))
#nを最大化，kはnの半分にできる限り近い数を取る
ai=max(a)
a.sort()
l=0
r=n-2
while l<r:
    if abs(ai//2-a[l])<abs(ai//2-a[r]):
        r-=1
    else:
        l+=1
print(ai,a[l])
