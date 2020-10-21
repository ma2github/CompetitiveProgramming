def main():
    x=input()
    idx=0
    while idx<len(x):
        if x[idx:idx+2]=='ch':
            idx+=2
        elif x[idx]=='o' or x[idx]=='k' or x[idx]=='u':
            idx+=1
        else:
            print('NO')
            return
    print('YES')
main()
