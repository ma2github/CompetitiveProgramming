#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin>>s;
  map<char,ll>memo;
  for(auto c:s)memo[c]++;
  string ans;
  memo.size()==2&memo[s[0]]==2?ans="Yes":ans="No";
  cout<<ans<<endl;
  return 0;
}
