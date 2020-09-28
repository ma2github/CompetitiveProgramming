#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  n--;
  for(int i=-n;i<=n;i++)cout<<k+i,i<n?cout<<' ':cout<<endl;
  return 0;
}
