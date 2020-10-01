#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(n) for(ll i=0;i<n;i++)
int main(){
  ll n,ans=0;
  cin>>n;
  vector<ll>a(n),sm(1e5+10,0);
  rep(n)cin>>a[i],sm[a[i]]++;
  rep(1e5+1){
    sm[i+1]+=sm[i];
    ans+=sm[i+1]==n/2;
    if(sm[i+1]>n/2)break;
  }
  cout<<ans<<endl;
  return 0;
}
