#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  a=2025-a;
  for(int i=1;i<10;i++)for(int j=1;j<10;j++)if(i*j==a)cout<<i<<" x "<<j<<endl;
  return 0;
}
