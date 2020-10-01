#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll l,r,ans=2019;
  cin>>l>>r;
  ll modl=l%2019;
  if(modl+(r-l)>2018|!modl){cout<<0<<endl;return 0;}
  for(ll i=l;i<r;i++)for(ll j=i+1;j<=r;j++)ans=min(ans,i*j%2019);
  cout<<ans<<endl;
  return 0;
}
