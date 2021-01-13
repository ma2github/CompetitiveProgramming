def main():
    n,q=map(int,input().split())
    s=input()
    for _ in range(q):
        l,r=map(int,input().split())
        l-=1
        ss=s[l:r]
        print('Yes' if (ss[0] in s[:l]) or (ss[-1] in s[r:]) else 'No')
tt=int(input())
for _ in range(tt):
    main()
