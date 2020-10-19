a,b=map(int,input().split())
if a<b:
    if a==1:
        print('Alice')
    else:
        print('Bob')
elif a==b:
    print('Draw')
else:
    if b!=1:
        print('Alice')
    else:
        print('Bob')
