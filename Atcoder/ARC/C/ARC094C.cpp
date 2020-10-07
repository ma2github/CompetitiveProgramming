#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int f,s,t,sm;
  f=max(a,max(b,c));
  t=min(a,min(b,c));
  sm=a+b+c;
  s=sm-f-t;
  int ans;
  int fms=f-s,fmt=f-t;
  (sm&1)^(f&1)?ans=(fms+1)/2+((fms+1)&1)+((fmt+1)&1)+(fmt+1)/2:ans=fms/2+fmt/2+(fmt&1);
  cout<<ans<<endl;
  return 0;
}
