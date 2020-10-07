#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(n) for(ll i=0;i<n;i++)
int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll>a(n),b(n);
  vector<pair<ll,ll>>ab(n);
  rep(n)cin>>a[i]>>b[i],ab[i]={a[i],b[i]};
  sort(ab.begin(),ab.end());
  ll ans=0;
  rep(n)ans+=ab[i].first*min(m,ab[i].second),m-=min(m,ab[i].second);
  cout<<ans<<endl;
  return 0;
}
