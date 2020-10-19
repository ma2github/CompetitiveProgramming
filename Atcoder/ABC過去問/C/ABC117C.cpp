#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> x(m);
  for(int i=0; i < m; ++i)cin>>x[i];
  if(n>=m){cout<<0<<endl; return 0;}
  sort(x.begin(),x.end());
  vector<int>dist(m-1);
  for(int i=0; i < m-1; ++i)dist[i]=x[i+1]-x[i];
  sort(dist.begin(),dist.end());
  int ans=0;
  for(int i=0; i <m-n;i++)ans+=dist[i];
  cout<<ans<<endl;
  return 0;
}
