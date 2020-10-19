#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long double ans=0;
  while(n--){
    long double xi;
    string ui;
    cin>>xi>>ui;
    ui=="JPY"?xi:xi*=380000.0;
    ans+=xi;
  }
  cout<<ans<<endl;
  return 0;
}
