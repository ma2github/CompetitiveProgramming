#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  vector<int> t(n);
  rep(n)cin>>t[i];
  int sm=accumulate(t.begin(),t.end(),0);
  int m;
  cin>>m;
  int p,x;
  rep(m){
    cin>>p>>x;
    p--;
    cout<<sm+x-t[p]<<endl;
  }
  return 0;
}
