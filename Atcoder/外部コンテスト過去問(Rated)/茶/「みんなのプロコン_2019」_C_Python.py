def main(k,a,b):
    if a>b:
        return 1+k
    if k<=a:
        return 1+k
    elif (k-a+1)%2==0:
        return max(1+k,b+(b-a)*((k-a+1)//2-1))
    else:
        return max(1+k,1+a+(b-a)*((k-a+1)//2))
k,a,b=map(int,input().split())
print(main(k,a,b))
