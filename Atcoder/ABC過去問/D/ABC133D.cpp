#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  ll sm=0,sm1=0;
  rep(n)cin>>a[i],sm+=a[i];
  rep(n)sm1+=a[i]*(i&1);
  vector<ll>ans(n);
  ans[0]=sm-2*sm1;
  rep(n-1)ans[i+1]=2*a[i]-ans[i];
  rep(n)cout<<ans[i],i<n-1?cout<<' ':cout<<endl;
  return 0;
}
