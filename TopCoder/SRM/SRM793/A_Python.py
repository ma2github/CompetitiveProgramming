h=input()
v=input()
ans=['.'*len(h)]*len(v)
if set(h)&set(v):
    for ch in h:
        if ch in v:
            for i in range(len(v)):
                ans[i]=ans[i][:h.index(ch)]+v[i]+ans[i][h.index(ch)+1:]
            ans[v.index(ch)]=h
            for x in ans:
                print(x)
            exit()
else:
    print()
