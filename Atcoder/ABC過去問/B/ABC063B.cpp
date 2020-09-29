#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  size_t sz=s.size();
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),end(s));
  sz==s.size()?cout<<"yes":cout<<"no",cout<<endl;
  return 0;
}
