#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  n++;
  int ans=0;
  while(--n){
    int a,b;
    cin>>a>>b;
    ans+=b-a+1;
  }
  cout<<ans<<endl;
  return 0;
}
