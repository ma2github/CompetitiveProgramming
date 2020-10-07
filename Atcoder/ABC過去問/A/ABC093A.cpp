#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  string ans;
  s=="abc"?ans="Yes":ans="No";
  cout<<ans<<endl;
  return 0;
}
