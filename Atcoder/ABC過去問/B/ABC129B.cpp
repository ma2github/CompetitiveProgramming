#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> s(n+1,0);
  for(int i=0;i<n;i++)cin>>s[i+1],s[i+1]+=s[i];
  int ans=1e10;
  for(int i=0;i<n;i++)ans=min(ans,abs(s[n]-2*s[i]));
  cout<<ans<<endl;
  return 0;
}
