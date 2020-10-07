#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define rep(n) for(ll i=0;i<n;i++)
vector<vector<ll>>v(2e5+10);
vector<ll>ans(2e5+10,0);
void dfs(ll index,ll root){
  ans[index]+=ans[root];
  for(auto child:v[index])if(child!=root)dfs(child,index);
}
int main(){
  ll n,q;
  cin>>n>>q;
  rep(n-1){
    ll s,t;
    cin>>s>>t;
    v[s].push_back(t);
    v[t].push_back(s);
  }
  rep(q){
    ll p,val;
    cin>>p>>val;
    ans[p]+=val;
  }
  dfs(1,0);
  rep(n)cout<<ans[i+1],i<n-1?cout<<' ':cout<<endl;
  return 0;
}
