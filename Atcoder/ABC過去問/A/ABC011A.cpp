#include<bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin>>m;
  m=(m+1)%12;
  m+=12*!m;
  cout<<m<<endl;
  return 0;
}
