#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  vector<pair<int,int>>ab(n);
  int ai,bi;
  rep(n)cin>>ai>>bi,ab[i]={bi,ai};
  sort(ab.begin(),ab.end());
  int t=0;
  rep(n){
    t+=ab[i].second;
    if(t>ab[i].first){cout<<"No";return 0;}
  }
  cout<<"Yes"<<endl;
  return 0;
}
