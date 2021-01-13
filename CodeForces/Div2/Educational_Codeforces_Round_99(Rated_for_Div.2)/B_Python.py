def main():
    x=int(input())
    cur=0
    cnt=0
    while cur<x:
        cnt+=1
        cur+=cnt
    print(cnt+1 if cur-1==x else cnt)
tt=int(input())
for _ in range(tt):
    main()
