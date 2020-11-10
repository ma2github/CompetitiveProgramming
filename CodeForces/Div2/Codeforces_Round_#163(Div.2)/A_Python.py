kind=['RR','GG','BB']
n=int(input())
s=input()
ans=0
for i in range(n):
    ans+=s[i:i+2] in kind
print(ans)
