s=input()
t=input()
for i in range(len(s)-len(t),-1,-1):
    index=i
    while (index<i+len(t)) and (s[index]==t[index-i] or s[index]=='?'):
        index+=1
    if index==i+len(t):
        ans=s[:i]+t+s[index:]
        print(ans.replace('?','a'))
        exit()
print('UNRESTORABLE')
