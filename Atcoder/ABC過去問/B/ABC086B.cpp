#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  a+=b;
  int n=stoi(a);
  for(int i=1;i*i<=n;i++){
    if(i*i==n){cout<<"Yes"<<endl;return 0;}
  }
  cout<<"No"<<endl;
  return 0;
}
