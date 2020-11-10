s=input()
index=len(s)
while index:
    if s[index-7:index]=='dreamer':
        index-=7
    elif s[index-6:index]=='eraser':
        index-=6
    elif s[index-5:index]=='dream' or s[index-5:index]=='erase':
        index-=5
    else:
        print('NO')
        exit()
print('YES')
