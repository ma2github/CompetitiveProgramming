s=[input() for _ in range(12)]
ans=0
for si in s:
    ans+='r' in si
print(ans)
