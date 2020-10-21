s=[input() for _ in range(3)]
i=[0]*3
cur=0
while True:
    i[cur]+=1
    if s[cur][i[cur]-1]=='a':
        cur=0
    elif s[cur][i[cur]-1]=='b':
        cur=1
    else:
        cur=2
    if i[cur]==len(s[cur]):
        print(chr(cur+65))
        break
