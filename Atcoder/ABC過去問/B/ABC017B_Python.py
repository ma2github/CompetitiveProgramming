x=input()
idx=0
while idx<len(x):
    if x[idx:idx+2]=='ch':
        idx+=2
    elif x[idx] in 'oku':
        idx+=1
    else:
        print('NO')
        exit(0)
print('YES')
