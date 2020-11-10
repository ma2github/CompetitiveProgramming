h,w=map(int,input().split())
for i in range(h):
    s=list(input().split())
    if 'snuke' in s:
        print(str(chr(65+s.index('snuke')))+str(i+1))
        exit()
