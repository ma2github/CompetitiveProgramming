#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  string ans;
  for(auto c:s){
    char x;
    ans.size()?(c>='a'?x=c:x=c-'A'+'a'):(c>='a'?x=c-'a'+'A':x=c);
    ans.push_back(x);
  }
  cout<<ans<<endl;
  return 0;
}
