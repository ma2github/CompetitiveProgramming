def main():
    w=input()
    for i in range(26):
        if w.count(chr(97+i))%2:
            print('No')
            return
    print('Yes')
main()
