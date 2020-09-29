#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  size_t sz=s.size();
  for(int i=0;i<sz-2;i++)if(s[i]==s[i+1]&&s[i+1]==s[i+2]){cout<<"Yes"<<endl;return 0;}
  cout<<"No"<<endl;
  return 0;
}
