#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int t,a;
  cin>>t>>a;
  t*=1000,a*=1000;
  int cur=1e9,ans;
  for(int i=1;i<=n;i++){
    int hi;
    cin>>hi;
    if(cur>abs(t-hi*6-a))cur=abs(t-hi*6-a),ans=i;
  }
  cout<<ans<<endl;
  return 0;
}
