#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  bool f=true;
  for(auto c:s){
    if(f)cout<<c,f=false;
    else f=true;
  }
  cout<<endl;
  return 0;
}
