from datetime import datetime,timedelta

ymd=input()
date_list=[datetime(int(ymd[:4]),int(ymd[5:7]),int(ymd[8:])) + timedelta(days=i) for i in range(365)]
date_str_list = [d.strftime("%Y/%m/%d") for d in date_list]
for cur in date_str_list:
    if int(cur[:4])%((int(cur[5:7]))*(int(cur[8:])))==0:
        print(cur)
        exit(0)
