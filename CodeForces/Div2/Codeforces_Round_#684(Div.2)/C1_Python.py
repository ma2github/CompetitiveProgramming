def main():
    n,m=map(int,input().split())
    s=[input() for _ in range(n)]
    ans=[]
    for i in range(m-1):
        for j in range(n-1):
            if s[j][i:i+2].count('1')+s[j+1][i:i+2].count('1')==4:
                s[j]=s[j][:i]+'10'+s[j][i+2:]
                s[j+1]=s[j+1][:i]+'00'+s[j+1][i+2:]
                ans.append([j+1,i+2,j+2,i+1,j+2,i+2])
            if s[j][i:i+2].count('1')+s[j+1][i:i+2].count('1')==1:
                index= 1*('1' in s[j][i:i+2])
                index2=s[j+1-index][i:i+2].index('1')
                s[j+1-index]=s[j+1-index][:i]+'00'+s[j+1-index][i+2:]
                s[j+index]=s[j+index][:i]+'11'+s[j+index][i+2:]
                ans.append([j+2-index,i+index2+1,j+index+1,i+1,j+index+1,i+2])
            if s[j][i:i+2].count('1')+s[j+1][i:i+2].count('1')==2:
                if s[j][i:i+2].count('1')==2:
                    s[j]=s[j][:i]+'10'+s[j][i+2:]
                    s[j+1]=s[j+1][:i]+'11'+s[j+1][i+2:]
                    ans.append([j+1,i+2,j+2,i+1,j+2,i+2])
                elif s[j][i:i+2].count('1')==1:
                    #index1=s[j][i:i+2].index('0')
                    index2=s[j+1][i:i+2].index('1')
                    index3=s[j][i:i+2].index('0')
                    index4=s[j+1][i:i+2].index('0')
                    mid0='11'
                    mid='10'
                    #if s[j][i:i+2]=='10':mid0='11'
                    if s[j+1][i:i+2]=='10':mid='01'
                    s[j]=s[j][:i]+mid0+s[j][i+2:]
                    s[j+1]=s[j+1][:i]+mid+s[j+1][i+2:]
                    ans.append([j+2,i+index2+1,j+1,i+index3+1,j+2,i+index4+1])
                else:
                    s[j]=s[j][:i]+'11'+s[j][i+2:]
                    s[j+1]=s[j+1][:i]+'10'+s[j+1][i+2:]
                    ans.append([j+2,i+2,j+1,i+1,j+1,i+2])
            if s[j][i:i+2].count('1')+s[j+1][i:i+2].count('1')==3:
                if s[j][i:i+2].count('1')==2:
                    ans.append([j+1,i+1,j+1,i+2,j+2,i+s[j+1][i:i+2].index('1')+1])
                else:
                    ans.append([j+2,i+1,j+2,i+2,j+1,i+s[j][i:i+2].index('1')+1])
                s[j]=s[j][:i]+'00'+s[j][i+2:]
                s[j+1]=s[j+1][:i]+'00'+s[j+1][i+2:]
    print(len(ans))
    for a,b,c,d,e,f in ans:
        print(a,b,c,d,e,f)
t=int(input())
for _ in range(t):
    main()
