def main():
    n=int(input())
    s=input()
    if n%2==0:
        print(-1)
        return
    ok='b'
    n-=1
    for i in range(1,n//2+1):
        if i%3==1:
            ok='a'+ok+'c'
        elif i%3==2:
            ok='c'+ok+'a'
        else:
            ok='b'+ok+'b'
    if s==ok:
        print(n//2)
    else:
        print(-1)
main()
