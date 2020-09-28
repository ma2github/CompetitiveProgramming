#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  long double bunbo=0;
  for(int i=0;i<n;i++)cin>>a[i],bunbo+=(long double)1/(long double)a[i];
  long double ans=1/bunbo;
  cout<<ans<<endl;
  return 0;
}
