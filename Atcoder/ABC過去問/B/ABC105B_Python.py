def main():
    n=int(input())
    while n>=0:
        if n%4==0:
            print("Yes")
            return
        n-=7
    print("No")
main()
