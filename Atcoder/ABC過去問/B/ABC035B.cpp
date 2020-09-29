#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int a;
  cin>>s>>a;
  int x=0,y=0,cnt=0;
  for(auto c:s)c=='U'?y++:(c=='D'?y--:(c=='L'?x--:(c=='R'?x++:cnt++)));
  int ans=abs(x)+abs(y);
  if(a==1)ans+=cnt;
  else ans=max(ans-cnt,(cnt-ans)%2);
  cout<<ans<<endl;
  return 0;
}
