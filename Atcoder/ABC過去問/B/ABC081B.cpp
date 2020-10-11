#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=30;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    for(int j=0;j<ans;j++)if((a>>j)&1){ans=j;break;}
  }
  cout<<ans<<endl;
  return 0;
}
