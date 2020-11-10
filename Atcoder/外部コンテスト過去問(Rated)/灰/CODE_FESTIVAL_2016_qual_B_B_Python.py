n,a,b=map(int,input().split())
s=input()
cnt=0
cntb=0
for c in s:
    if ((c=='a') or (c=='b' and cntb<b)) and cnt<a+b:
        print('Yes')
        cnt+=1
        cntb+=c=='b'
        continue
    print('No')
