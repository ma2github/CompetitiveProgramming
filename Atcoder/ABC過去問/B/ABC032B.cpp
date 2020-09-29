#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n;
  cin>>s>>n;
  size_t sz=s.size();
  if(sz<n){cout<<0<<endl;return 0;}
  set<string>memo;
  for(int i=0;i<sz-n+1;i++)memo.insert(s.substr(i,n));
  cout<<memo.size()<<endl;
  return 0;
}
