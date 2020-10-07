#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int ml=0,mr=1e5+10;
  int l,r;
  for(int i=0;i<n;i++)cin>>l>>r,ml=max(ml,l),mr=min(mr,r);
  int ans=max(0,mr-ml+1);
  cout<<ans<<endl;
  return 0;
}
