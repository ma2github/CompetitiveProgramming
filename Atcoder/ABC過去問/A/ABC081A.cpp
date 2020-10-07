#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=stoi(s);
  int ans=0;
  while(n)ans+=n%10,n/=10;
  cout<<ans<<endl;
  return 0;
}
