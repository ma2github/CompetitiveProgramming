sx,sy,tx,ty=map(int,input().split())
ans1='U'*(ty-sy)+'R'*(tx-sx)
ans2=ans1.replace('U','D').replace('R','L')
ans3='L'+ans1.replace('UR','UUR')+'RD'
ans4='R'+ans2.replace('DL','DDL')+'LU'
print(ans1+ans2+ans3+ans4)
