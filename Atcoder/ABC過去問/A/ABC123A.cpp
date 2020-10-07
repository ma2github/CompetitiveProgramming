#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=6;
  int mx=0,mn=1e9;
  int a;
  while(--n)cin>>a,mx=max(a,mx),mn=min(mn,a);
  int k;
  cin>>k;
  string ans;
  mx-mn>k?ans=":(":ans="Yay!";
  cout<<ans<<endl;
  return 0;
}
