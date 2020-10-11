#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s=to_string(n);
  int sm=0;
  for(auto c:s)sm+=c-'0';
  string ans;
  n%sm?ans="No":ans="Yes";
  cout<<ans<<endl;
  return 0;
}
