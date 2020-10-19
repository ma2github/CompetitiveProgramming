#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=753;
  for(int i=0; i<s.size();i++){
    ans=min(ans,abs(753-stoi(s.substr(i,3))));
  }
  cout<<ans<<endl;
  return 0;
}
