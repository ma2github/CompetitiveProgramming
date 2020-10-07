#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int hmax=0;
  int ans=0;
  while(n){
    int hi;
    cin>>hi;
    ans+=hmax<=hi;
    hmax=max(hmax,hi);
    n--;
  }
  cout<<ans<<endl;
  return 0;
}
