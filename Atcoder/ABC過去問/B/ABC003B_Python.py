def main():
    s=input()
    t=input()
    ln=len(s)
    ok='atcoder'
    for i in range(ln):
        if s[i]=='@' or t[i]=='@':
            if s[i]==t[i]:
                continue
            elif s[i] in ok or t[i] in ok:
                continue
            else:
                print('You will lose')
                return
        elif s[i]!=t[i]:
            print('You will lose')
            return
    print('You can win')
main()
