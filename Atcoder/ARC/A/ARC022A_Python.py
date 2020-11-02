s=input()
it=len(s)
for i in 'TCI':
    if (i not in s[:it]) and (i.lower() not in s[:it]):
        print('NO')
        exit(0)
    elif (i in s[:it]) and (i.lower() in s[:it]):
        it=max(s[:it].rfind(i),s[:it].rfind(i.lower()))
    else:
        it=s[:it].rfind(i.lower()) if i.lower() in s[:it] else s[:it].rfind(i)
print('YES')
