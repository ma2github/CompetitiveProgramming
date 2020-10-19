#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  map<int,int>mp;
  for(int i=0; i<n;i++){
    int ki;
    cin>>ki;
    for(int j=0; j<ki; j++){
      int ai;
      cin>>ai;
      mp[ai]++;
    }
  }
  int ans=0;
  for(auto c:mp)ans+=c.second==n;
  cout<<ans<<endl;
  return 0;
}
