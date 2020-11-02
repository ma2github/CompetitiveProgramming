s=input()
key='WBWBWWBWBWBW'
ans='DoReMiFaSoLaSi'
idx=0
for i in range(7):
    if s[:12]==key[idx:]+key[:idx]:
        print(ans[2*i:2*i+2])
        exit(0)
    idx+=1
    while key[idx]=='B':
        idx+=1
