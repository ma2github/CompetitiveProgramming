a,b=map(int,input().split())
print('Zero' if (a>0)^(b>0) else 'Positive' if a>0 or min(b-a+1,-a)%2==0 else 'Negative')
