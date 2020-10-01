#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
  ll a,b,ans=0;
  cin>>a>>b;
  vector<vector<ll>>v(a,vector<ll>(b,0));
  for(ll i=0;i<a;i++)for(ll j=0;j<b;j++)cin>>v[i][j];
  for(ll i=0;i<a;i++)for(ll k=i+1;k<a;k++){
    ll dist=0;
    for(ll j=0;j<b;j++)dist+=(v[k][j]-v[i][j])*(v[k][j]-v[i][j]);
    ans+=dist-(ll)sqrt((ld)dist)*(ll)sqrt((ld)dist)==0;
  }
  cout<<ans<<endl;
  return 0;
}
