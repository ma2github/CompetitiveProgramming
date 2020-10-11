#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int k,s;
  cin>>k>>s;
  int ans=0;
  rep(x,k+1)rep(y,k+1)ans+=(s-x-y<=k)&&(s-x-y>=0);
  cout<<ans<<endl;
  return 0;
}
