s=input()
ans=sum(list(map(int,s[::2])))-sum(list(map(int,s[1::2])))
print(ans)
