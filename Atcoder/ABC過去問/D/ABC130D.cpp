#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,a,n) for(int i=a;i<n;i++)
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll>a(n),sm(n+1,0);
  rep(i,0,n)cin>>a[i],sm[i+1]=sm[i]+a[i];
  ll ans=0;
  ll r=0;
  rep(i,0,n+1){
    rep(j,r,n+1){
      if(sm[j]-sm[i]>=k){r=j;break;}
      else if(j==n)r=n+1;
    }
    ans+=n-r+1;
  }
  cout<<ans<<endl;
  return 0;
}
