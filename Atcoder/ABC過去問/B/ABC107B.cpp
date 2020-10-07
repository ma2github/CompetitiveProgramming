#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int h,w;
  cin>>h>>w;
  vector<bool>ngh(h,true),ngw(w,true);
  vector<vector<char>>a(h,vector<char>(w));
  rep(i,h)rep(j,w)cin>>a[i][j],ngh[i]=ngh[i]&a[i][j]=='.',ngw[j]=ngw[j]&a[i][j]=='.';
  rep(i,h){
    if(ngh[i])continue;
    rep(j,w){
      if(ngw[j])continue;
      cout<<a[i][j];
    }
    cout<<endl;
  }
  return 0;
}
