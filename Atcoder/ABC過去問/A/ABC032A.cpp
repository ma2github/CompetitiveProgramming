#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  while(1){
    if(!(c%a)&&!(c%b)){cout<<c<<endl;return 0;}
    c++;
  }
  return 0;
}
