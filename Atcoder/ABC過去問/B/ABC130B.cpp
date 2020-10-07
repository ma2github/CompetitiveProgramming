#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  rep(n)cin>>v[i];
  int d=0,ans=1;
  rep(n){
    d+=v[i];
    if(d>k)break;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
