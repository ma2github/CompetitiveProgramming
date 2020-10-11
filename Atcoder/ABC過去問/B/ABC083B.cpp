#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int ans=0;
  for(int i=1;i<=n;i++){
    string s=to_string(i);
    int sm=0;
    for(auto c:s)sm+=c-'0';
    ans+=i*((sm>=a)&&(sm<=b));
  }
  cout<<ans<<endl;
  return 0;
}
