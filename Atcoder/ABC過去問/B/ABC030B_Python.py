n,m=map(int,input().split())
print(min(abs(m*6-(n*30+30*(m/60)))%360,360-abs(m*6-(n*30+30*(m/60)))%360))
