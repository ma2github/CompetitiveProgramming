#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  bool f=false;
  f=s[5]=='1'|s[6]>'4';
  string ans;
  f?ans="TBD":ans="Heisei";
  cout<<ans<<endl;
  return 0;
}
