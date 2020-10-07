#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  n++;
  map<int,int>memo;
  int a;
  while(--n)cin>>a,memo[a]++;
  cout<<memo.size()<<endl;
  return 0;
}
