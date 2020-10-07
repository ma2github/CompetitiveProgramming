#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  for(int i=a;i<a+k;i++){if(i>b){return 0;}cout<<i<<endl;}
  for(int i=b-k+1;i<=b;i++){if(i<a+k)continue;cout<<i<<endl;}
  return 0;
}
