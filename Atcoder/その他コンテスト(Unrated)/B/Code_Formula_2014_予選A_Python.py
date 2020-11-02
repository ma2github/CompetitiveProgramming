a,b=map(int,input().split())
p=list(map(int,input().split()))
q=list(map(int,input().split()))
ans=['7 8 9 0',' 4 5 6 ','  2 3  ','   1   ']
for i in range(10):
    ret='.'
    if i in p:
        ret='.'
    else:
        ret='o' if i in q else 'x'
    for j in range(4):
        if str(i) in ans[j]:
            ans[j]=ans[j][:ans[j].index(str(i))]+ret+ans[j][ans[j].index(str(i))+1:]
for ansi in ans:
    print(ansi)
