#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(auto c:s){
    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o')continue;
    cout<<c;
  }
  cout<<endl;
  return 0;
}
