a=set(input().split())
for ai in a:
    if ai not in '1974' or len(a)!=4:
        print('NO')
        exit(0)
print('YES')
