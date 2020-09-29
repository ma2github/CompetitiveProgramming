#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int g=gcd(a,b);
  cout<<a/g<<':'<<b/g<<endl;
  return 0;
}
