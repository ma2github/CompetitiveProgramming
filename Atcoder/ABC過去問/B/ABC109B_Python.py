def main():
    n=int(input())
    st=[input() for i in range(n)]
    st1=list(set(st))
    if len(st1)!=n:
        print("No")
    else:
        for i in range(n-1):
            if st[i][-1]!=st[i+1][0]:
                print("No")
                return
        print("Yes")
main()
