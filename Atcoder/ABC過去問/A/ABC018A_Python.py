a=[int(input()) for _ in range(3)]
for ai in a:
    if ai==max(a):
        print(1)
    elif ai==min(a):
        print(3)
    else:
        print(2)
