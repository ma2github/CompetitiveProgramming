def main():
    x,y=map(int,input().split())
    pena=0
    if abs(x-y)>1:pena=abs(x-y)-1
    print(x+y+pena)
tt=int(input())
for _ in range(tt):
    main()
