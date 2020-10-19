#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int ans;
  b%a?ans=b-a:ans=a+b;
  cout<<ans<<endl;
  return 0;
}
