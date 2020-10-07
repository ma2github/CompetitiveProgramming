#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int sz=s.size();
  int i=0;
  int ok=0;
  while(i<sz)ok+=(s[i]=='1'&&i&1)||(s[i]=='0'&&!(i&1)),i++;
  cout<<min(ok,sz-ok)<<endl;
  return 0;
}
