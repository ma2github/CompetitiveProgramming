#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<n;i++)
int main(){
  int n,k;
  cin>>n>>k;
  vector<ll> a(n);
  int cntm=0,cntp=0,cntz=0;
  rep(n)cin>>a[i],cntm+=a[i]<0,cntz+=a[i]==0;
  cntp=n-cntz-cntm;
  k-=cntz;
  vector<ll> m(cntm+1,0),p;
  p.push_back(0);
  rep(n){
    if(cntm-i>0)m[cntm-i]=a[i];
    else if(cntz)cntz--;
    else p.push_back(a[i]);
  }
  ll ans=2e9;
  cntm=m.size()-1;
  rep(k+1){
    if(k-i>cntp)continue;
    ans=min(ans,min(-m[i],p[k-i])*2+max(-m[i],p[k-i]));
    if(i==cntm)break;
  }
  cout<<ans<<endl;
  return 0;
}
