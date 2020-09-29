#include<bits/stdc++.h>
using namespace std;
int main(){
  long double a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  long double vax=c-a,vay=d-b,vbx=e-a,vby=f-b;
  long double ans=abs(vax*vby-vay*vbx)/2;
  printf("%.15Lf/n",ans);
  return 0;
}
