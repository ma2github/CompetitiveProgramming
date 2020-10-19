def main():
    n,m,x,y=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    for i in range(max(a),min(b)):
        if x<i+1 and i+1<=y:
            print('No War')
            return
    print('War')
main()
