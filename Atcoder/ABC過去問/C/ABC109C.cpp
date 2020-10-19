#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> v(n);
  for(int i;i<n;i++)cin>>v[i],v[i]-=x,v[i]=abs(v[i]);
  cout<<reduce(v.begin(),v.end(),0,gcd<int,int>)<<endl;
  return 0;
}
