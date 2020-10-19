#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  int ans=-1;
  int l=0,r=0;
  while(l<n){
    while(!v[l]&&l<n)l++;
    r=l;
    while(v[r]&&r<n)v[r]--,r++;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
