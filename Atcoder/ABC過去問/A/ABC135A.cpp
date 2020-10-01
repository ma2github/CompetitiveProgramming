#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  (a&1)^(b&1)?cout<<"IMPOSSIBLE":cout<<(a+b)/2,cout<<endl;
  return 0;
}
