#include<bits/stdc++.h>
using namespace std;
int main(){
  char x,y;
  cin>>x>>y;
  char ans;
  x>y?ans='>':x==y?ans='=':ans='<';
  cout<<ans<<endl;
  return 0;
}
