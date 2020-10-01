#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;
  cin>>n;
  vector<ll>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  ll ans=0;
  for(int i=0;i<n-2;i++)ans+=a[i+1]<max(a[i],a[i+2])&a[i+1]>min(a[i],a[i+2]);
  cout<<ans<<endl;
  return 0;
}
