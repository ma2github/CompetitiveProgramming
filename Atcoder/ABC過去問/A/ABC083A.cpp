#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  string ans;
  a+b>c+d?ans="Left":a+b==c+d?ans="Balanced":ans="Right";
  cout<<ans<<endl;
  return 0;
}
