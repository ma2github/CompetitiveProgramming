#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n,q;
  string s;
  cin>>n>>q>>s;
  vector<int>sm(n,0);
  rep(n-1)sm[i+1]+=sm[i]+(s[i]=='A'&&s[i+1]=='C');
  rep(q){
    int l,r;
    cin>>l>>r;
    --l,--r;
    cout<<sm[r]-sm[l]<<endl;
  }
  return 0;
}
