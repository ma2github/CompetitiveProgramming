def main():
    a,b=map(int,input().split())
    ans=''
    c=0
    while a:
        if b:
            ans+='a'
            b-=1
        elif c==0:
            ans+='b'
            c+=1
        else:
            ans+='c'
            c-=1
            b+=1
        a-=1
    print(ans)
tt=int(input())
for _ in range(tt):
    main()
