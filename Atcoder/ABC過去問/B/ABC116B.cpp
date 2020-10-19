#include<bits/stdc++.h>
using namespace std;
int main(){
  int s;
  cin>>s;
  map<int,int>m;
  int ans=1;
  while(!m[s]){
    m[s]++;
    if(s&1)s=s*3+1;
    else s/=2;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
