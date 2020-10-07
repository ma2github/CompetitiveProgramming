#include<bits/stdc++.h>
using namespace std;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  rep(10)c=c*a-b,cout<<c,c<9?cout<<' ':cout<<endl;
  return 0;
}
