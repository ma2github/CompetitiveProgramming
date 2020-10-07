#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll intpow(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a;a*=a;b/=2;}return ans;}
ll solve(ll n){
  if(n&1)return 0;
  ll res=0;
  for(ll i=1;i<26;i++)res+=n/2/intpow(5LL,i);
  return res;
}
int main(){
  ll n;
  cin>>n;
  ll ans=solve(n);
  cout<<ans<<endl;
  return 0;
}
