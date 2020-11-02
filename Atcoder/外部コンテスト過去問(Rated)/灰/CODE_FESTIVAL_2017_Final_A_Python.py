s=input()
idx=[0,4,6,8]
for i in range(1<<4):
    ret=s
    for j in range(4):
        if (i>>j)&1:
            ret=ret[:idx[j]]+'A'+ret[idx[j]:]
    if ret=='AKIHABARA':
        print('YES')
        exit(0)
print('NO')
