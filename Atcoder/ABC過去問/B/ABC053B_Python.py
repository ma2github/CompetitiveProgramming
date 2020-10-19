s=input()
ansa=-1
ansz=10**9
for i in range(10**6):
    if s[i]=='A' and ansa==-1:
        ansa=i
    if s[-(i+1)]=='Z' and ansz==10**9:
        ansz=len(s)-i
    if ansa!=-1 and ansz!=10**9:
        break
print(ansz-ansa)
