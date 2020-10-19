def rotate(l,n):
    return l[n:]+l[:n]
def main():
    s=input()
    t=input()
    l=list(s)
    m=list(t)
    for i in range(len(m)):
        l=rotate(l,1)
        if l==m:
            print('Yes')
            return
    print('No')
main()
