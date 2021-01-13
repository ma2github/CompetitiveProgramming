n=int(input())
a=list(map(int,input().split()))
s=set(a)
xor=0
if len(s)>3 or (len(s)==1 and s!={0}):
    print('No')
    exit()
for x in a:
    xor^=x
print('YNeos'[1-(xor==0)::2])
