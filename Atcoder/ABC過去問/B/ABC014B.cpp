#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  vector<int> v(a);
  int ans=0;
  for(int i=0;i<a;i++)cin>>v[i],ans+=v[i]*((b>>i)&1);
  cout<<ans<<endl;
  return 0;
}
