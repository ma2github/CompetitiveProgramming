#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string ans;
  n%10==9?ans="Yes":n/10==9?ans="Yes":ans="No";
  cout<<ans<<endl;
  return 0;
}
