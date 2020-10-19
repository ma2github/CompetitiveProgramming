def main():
    s=input()
    for i in range(1,len(s)//2):
        if s[:(len(s)-2*i)//2]==s[(len(s)-2*i)//2:len(s)-2*i]:
            print(len(s)-2*i)
            return
main()
