h,w=map(int,input().split())
a=['#'*(w+2)]
for i in range(h):
    a.append('#'+input()+'#')
a.append('#'*(w+2))
for ans in a:
  print(ans)
