#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int ans;
  a%b?ans=b-a%b:ans=0;
  cout<<ans<<endl;
  return 0;
}
