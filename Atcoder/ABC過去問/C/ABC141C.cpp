#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,q;
  cin>>n>>k>>q;
  vector<int>p(n,k-q);
  for(int i=0;i<q;i++){
    int ai;
    cin>>ai;
    ai--;
    p[ai]++;
  }
  for(int i=0;i<n;i++)p[i]>0?cout<<"Yes":cout<<"No",cout<<endl;
  return 0;
}
