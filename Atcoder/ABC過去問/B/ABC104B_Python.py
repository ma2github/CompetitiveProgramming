def main():
    s=input()
    if s[0]!='A' or s[1]=='C' or s[-1]=='C' or s.count('C')!=1:
        print("WA")
        return
    l=list(s)
    l.pop(0)
    for i in l:
        if i=='C':
            continue
        if i<'a':
            print("WA")
            return
    print("AC")
main()
