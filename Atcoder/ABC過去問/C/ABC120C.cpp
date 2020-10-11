#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  map<char,int>memo;
  for(auto c:s)memo[c]++;
  cout<<2*min(memo['1'],memo['0'])<<endl;
  return 0;
}
