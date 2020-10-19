w,h,n=map(int,input().split())
xya=[list(map(int,input().split())) for i in range(n)]
ans=w*h
l=0
r=w
u=h
d=0
for [xi,yi,ai] in xya:
    if ai==1:
        ans-=max(min(r,xi)-l,0)*max(u-d,0)
        l=max(xi,l)
    elif ai==2:
        ans-=max(r-max(l,xi),0)*max(u-d,0)
        r=min(r,xi)
    elif ai==3:
        ans-=max(r-l,0)*max(min(u,yi)-d,0)
        d=max(d,yi)
    else:
        ans-=max(r-l,0)*max(u-max(yi,d),0)
        u=min(u,yi)
print(ans)
