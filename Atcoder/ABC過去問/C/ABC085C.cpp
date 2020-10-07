#include<bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
int main(){
  int n,y;
  cin>>n>>y;
  y/=1000;
  rep(a,n+1)rep(b,n+1-a)if(9*a+4*b==y-n){cout<<a<<' '<<b<<' '<<n-a-b<<endl;return 0;}
  cout<<-1<<' '<<-1<<' '<<-1<<endl;
  return 0;
}
