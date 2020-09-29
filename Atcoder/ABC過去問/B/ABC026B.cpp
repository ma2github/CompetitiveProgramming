#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>r(n);
  for(int i=0;i<n;i++)cin>>r[i];
  sort(r.begin(),r.end());
  long double ans=0;
  for(int i=n-1;i>=0;i--)(n-i)&1?ans+=r[i]*r[i]:ans-=r[i]*r[i];
  ans*=M_PI;
  printf("%.15Lf",ans);
  return 0;
}
