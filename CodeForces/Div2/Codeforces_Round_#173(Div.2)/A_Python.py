n=int(input())
ans=0
for _ in range(n):
    if '+' in input():
        ans+=1
    else:
        ans-=1
print(ans)
