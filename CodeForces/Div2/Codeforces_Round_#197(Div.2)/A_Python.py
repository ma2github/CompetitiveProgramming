s=input()
ans=''
for i in range(3):
    ans+=(str(i+1)+'+')*s.count(str(i+1))
print(ans[:-1])
