#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  rep(n)cin>>a[i];
  sort(a.begin(),a.end());
  int ans=a[n-1]/2;
  rep(n-1)ans+=a[i];
  cout<<ans<<endl;
  return 0;
}
