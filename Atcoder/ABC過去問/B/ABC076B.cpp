#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  n++;
  int ans=1;
  while(--n){
    ans<k?ans*=2:ans+=k;
  }
  cout<<ans<<endl;
  return 0;
}
