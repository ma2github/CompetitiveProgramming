#include<bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin>>m;
  int x=0,n=1e9;
  m++;
  while(--m){
    int a;
    cin>>a;
    x=max(x,a),n=min(n,a);
  }
  cout<<x-n<<endl;
  return 0;
}
