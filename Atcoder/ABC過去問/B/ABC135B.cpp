#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int cnt=0;
  int ai;
  for(int i=1;i<=n;i++)cin>>ai,cnt+=i!=ai;
  cnt>2?cout<<"NO":cout<<"YES",cout<<endl;
  return 0;
}
