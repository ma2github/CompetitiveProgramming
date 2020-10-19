w,a,b=map(int,input().split())
l=min(a,b)
r=max(a,b)
print(max(r-(l+w),0))
