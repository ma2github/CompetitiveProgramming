s=input()
cnt=0
old=''
for c in s:
    cnt+=1 if old==c else -cnt+1
    old=c
    if cnt>6:
        print('YES')
        exit()
print('NO')
