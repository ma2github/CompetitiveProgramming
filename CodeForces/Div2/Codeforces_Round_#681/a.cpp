#include<bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i,n) for(ll i=0;i<(n);++i)
bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
ll t,n;
std::vector<bool> ok(410,true);
std::vector<int> ans(410,0);
signed main(){
  cin>>t;
  rep(i,t){
    cin>>n;
    ll cnt=0;
    while(cnt<n){
      ans[cnt]=4*n-2*cnt;
      cnt++;
    }
    rep(k,n)cout<<ans[k]<<' ';
    cout<<endl;
  }
}
