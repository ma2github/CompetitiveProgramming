n=int(input())
a,b=map(int,input().split())
p=list(map(int,input().split()))
ans=[0]*3
for pi in p:
    if pi<=a:
        ans[0]+=1
    elif pi<=b:
        ans[1]+=1
    else:
        ans[2]+=1
print(min(ans))
