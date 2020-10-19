#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t;
  cin>>n>>t;
  int ans=1e8;
  while(n--){
    int ci,ti;
    cin>>ci>>ti;
    if(ti<=t)ans=min(ans,ci);
  }
  if(ans==1e8)cout<<"TLE"<<endl;
  else cout<<ans<<endl;
  return 0;
}
