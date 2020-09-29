#include<bits/stdc++.h>
using namespace std;
int main(){
  int h;
  cin>>h;
  int ans[3];
  for(int i=0;i<3;i++)ans[2-i]=h%60,h/=60;
  for(int i=0;i<3;i++)ans[i]<10?cout<<0:cout,cout<<ans[i],i<2?cout<<':':cout<<endl;
  return 0;
}
