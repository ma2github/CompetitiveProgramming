#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  cout<<max(a+b,max(a,b)*2-1)<<endl;
  return 0;
}
