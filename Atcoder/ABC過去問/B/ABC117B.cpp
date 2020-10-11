#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  int sm=0;
  for(int i=0;i<n-1;i++)sm+=a[i];
  string ans;
  sm<=a[n-1]?ans="No":ans="Yes";
  cout<<ans<<endl;
  return 0;
}
