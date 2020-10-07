#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>d(k),ng(10);
  rep(k)cin>>d[i],ng[d[i]]++;
  --n;
  while(++n){
    string s=to_string(n);
    bool f=true;
    for(auto c:s)if(ng[c-'0']){f=false;break;}
    if(f){cout<<n<<endl;return 0;}
  }
}
