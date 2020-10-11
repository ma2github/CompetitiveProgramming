#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll>a(n);
  map<ll,ll>memo;
  ll sm=0,cnt=0;
  rep(n)cin>>a[i],memo[a[i]]++,sm+=a[i];
  rep(m){
    ll bi,ci;
    cin>>bi>>ci;
    memo[ci]+=bi;
    sm+=bi*ci;
    cnt+=bi;
  }
  for(auto x:memo)sm-=x.first*min(cnt,x.second),cnt-=min(cnt,x.second);
  cout<<sm<<endl;
  return 0;
}
