#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  vector<int> v(n),c(n);
  rep(n)cin>>v[i];
  rep(n)cin>>c[i];
  int ans=0;
  rep(n)ans+=max(0,v[i]-c[i]);
  cout<<ans<<endl;
  return 0;
}
