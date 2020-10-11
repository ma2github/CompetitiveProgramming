#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,k;
  cin>>a>>b>>k;
  int cnt=0;
  for(int i=min(a,b);i>=1;i--){
    if(a%i|b%i)continue;
    cnt++;
    if(cnt<k)continue;
    cout<<i<<endl;
    return 0;
  }
}
