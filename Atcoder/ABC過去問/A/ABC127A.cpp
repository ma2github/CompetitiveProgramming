#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int ans;
  a<6?ans=0:a<13?ans=b/2:ans=b;
  cout<<ans<<endl;
  return 0;
}
