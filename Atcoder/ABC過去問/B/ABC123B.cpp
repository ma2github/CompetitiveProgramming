#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=6;
  int t;
  int sm=0,ans=0,modmax=0;
  while(--n)cin>>t,sm+=t,t%10?ans+=10-t%10:t,t%10?modmax=max(modmax,10-t%10):t;
  ans+=sm-modmax;
  cout<<ans<<endl;
  return 0;
}
