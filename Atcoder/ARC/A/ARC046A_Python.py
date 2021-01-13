n=int(input())
ans=str(((n%9)-1)%9+1)*((n-1)//9+1)
print(ans)
