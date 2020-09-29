#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans;
  a==b?ans=c:(a==c?ans=b:ans=a);
  cout<<ans<<endl;
  return 0;
}
