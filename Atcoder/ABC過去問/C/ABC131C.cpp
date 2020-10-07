#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll cc=b/c-(a-1)/c;
  ll dc=b/d-(a-1)/d;
  ll e=lcm(c,d);
  ll ec=b/e-(a-1)/e;
  cout<<b-a+1-cc-dc+ec<<endl;
  return 0;
}
