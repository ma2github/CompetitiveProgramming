#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int num=n;
  int sm=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    sm+=a;
    num-=!a;
  }
  int ans=(sm+num-1)/num;
  cout<<ans<<endl;
  return 0;
}
