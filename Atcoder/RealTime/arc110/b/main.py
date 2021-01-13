n=int(input())
t=input()
if ('111' in t) or ('00' in t) or ('010' in t):
    print(0)
    exit()
if t=='1':
    print(2*(10**10))
    exit()
if t=='11':
    print(10**10)
    exit()
if t[-1]=='1':
    print(10**10-t.count('0'))
else:
    print(10**10-(t.count('0')-1))
