#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ld s=(ld)a*(ld)b/2;
  int ans=(a==2*c&&b==2*d);
  cout<<s<<' '<<ans<<endl;
  return 0;
}
