#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  ll n;
  cin>>n;
  vector<ll>a(n),absa(n);
  ll cnt=0;
  rep(n)cin>>a[i],absa[i]=abs(a[i]),cnt+=a[i]<0;
  ll sm=accumulate(absa.begin(),absa.end(),0LL);
  sort(absa.begin(),absa.end());
  ll ans=sm;
  cnt&1?ans-=2*absa[0]:ans;
  cout<<ans<<endl;
  return 0;
}
