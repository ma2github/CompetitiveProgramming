#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  string s;
  cin>>a>>b>>s;
  int i=0;
  while(s[i]!='-')i++;
  if(i!=a){cout<<"No"<<endl;return 0;}
  i++;
  while(i<a+b+1){
    if(s[i]=='-'){cout<<"No"<<endl;return 0;}
    i++;
  }
  cout<<"Yes"<<endl;
  return 0;
}
