#include<bits/stdc++.h>
using namespace std;
int main(){
  string n;
  cin>>n;
  string ans;
  (stoi(n.substr(0,2))>12||n.substr(0,2)=="00")?((stoi(n.substr(2,2))>12||n.substr(2,2)=="00")?ans="NA":ans="YYMM"):(stoi(n.substr(2,2))>12||n.substr(2,2)=="00")?ans="MMYY":ans="AMBIGUOUS";
  cout<<ans<<endl;
  return 0;
}
