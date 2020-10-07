#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
#define ng(n) if(cnt[i]!=n){cout<<0<<endl;return 0;}
int main(){
  int n;
  cin>>n;
  vector<int>a(n),cnt(n,0);
  rep(n)cin>>a[i],cnt[a[i]]++;
  long long ans=1;
  rep(n){
    if(!i){
      if(n%2){
        ng(1);
      }else{
        ng(0);
      }
    }
    else if((i&1)^(n&1)){
      ng(2);
      ans*=2;
      ans%=1000000007;
    }else{
      ng(0);
    }
  }
  cout<<ans<<endl;
  return 0;
}
