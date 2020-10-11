#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=1;
  while(ans*ans<=n)ans++;
  ans--;
  ans*=ans;
  cout<<ans<<endl;
  return 0;
}
