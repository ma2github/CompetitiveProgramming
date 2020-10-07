#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin>>s;
  ll ans=0;
  int sz=s.size();
  ll i=0,cur=0;
  while(i<sz){
    cur=0;
    while(i<sz&&s[i]=='<')i++,cur++;
    ll cnt=0;
    while(i<sz&&s[i]=='>')cnt++,i++;
    ans+=cur*(cur+1)/2+cnt*(cnt+1)/2-min(cur,cnt);
  }
  cout<<ans<<endl;
  return 0;
}
