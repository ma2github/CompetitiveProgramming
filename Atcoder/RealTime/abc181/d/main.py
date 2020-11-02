import itertools
s=input()
if len(s)<4:
    l=[c for c in s]
    #print(l)
    for v in itertools.permutations(l):
        if int(''.join(list(v)))%8==0:
            print('Yes')
            exit(0)
    print('No')
    exit(0)
for i in range(100,1000):
    if i%8==0:
        stri=str(i)
        f=True
        for c in stri:
            if stri.count(c)>s.count(c):
                f=False
        if f==True:
            print('Yes')
            exit(0)
print('No')
