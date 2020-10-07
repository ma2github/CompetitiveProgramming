#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(n) for(ll i=0;i<n;i++)
#define all(a) a.begin(),a.end()
int main(){
  ll n;
  cin>>n;
  vector<ll>a(5);
  rep(5)cin>>a[i];
  ll ans=(n+*min_element(all(a))-1)/(*min_element(all(a)))+4;
  cout<<ans<<endl;
  return 0;
}
