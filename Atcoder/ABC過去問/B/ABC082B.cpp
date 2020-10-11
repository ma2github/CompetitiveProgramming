#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  string ans;
  s<t?ans="Yes":ans="No";
  cout<<ans<<endl;
  return 0;
}
