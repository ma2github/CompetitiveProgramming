#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>a(n+1),b(n);
  for(int i=0;i<n+1;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  long long ans=0;
  for(int i=0;i<n;i++)ans+=min(a[i]+a[i+1],b[i]),a[i+1]-=max(0,b[i]-a[i]),a[i+1]=max(0,a[i+1]);
  cout<<ans<<endl;
  return 0;
}
