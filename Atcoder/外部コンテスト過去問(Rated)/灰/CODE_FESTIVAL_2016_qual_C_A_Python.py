s=input()
f=1
if 'C' in s:
    f='F' in s[s.index('C'):]
print('YNeos'[1-f::2])
