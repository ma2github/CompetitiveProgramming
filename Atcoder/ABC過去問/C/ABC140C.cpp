#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int ans=0;
  vector<int>b(110);
  cin>>n;
  for(int i=0;i<n-1;i++)cin>>b[i];
  for(int i=1;i<n-1;i++)ans+=min(b[i],b[i-1]);
  ans+=b[n-2]+b[0];
  cout<<ans<<endl;
  return 0;
}
