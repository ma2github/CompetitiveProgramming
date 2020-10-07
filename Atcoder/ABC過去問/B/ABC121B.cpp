#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,m,c;
  cin>>n>>m>>c;
  vector<int>b(m);
  vector<vector<int>>a(n,vector<int>(m,0));
  rep(i,m)cin>>b[i];
  int ans=0;
  rep(i,n){
    int sm=c;
    rep(j,m)cin>>a[i][j],sm+=a[i][j]*b[j];
    ans+=sm>0;
  }
  cout<<ans<<endl;
  return 0;
}
