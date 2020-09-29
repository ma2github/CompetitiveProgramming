#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  bool fp,fm;
  fp=a+b==c,fm=a-b==c;
  char ans;
  fp?(fm?ans='?':ans='+'):(fm?ans='-':ans='!');
  cout<<ans<<endl;
  return 0;
}
