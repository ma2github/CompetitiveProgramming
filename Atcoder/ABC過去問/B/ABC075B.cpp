#include<bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int main(){
  int n,k;
  cin>>n>>k;
  vector<string>mp(n);
  for(int i=0;i<n;i++)cin>>mp[i];
  for(int i=0;i<n;i++)for(int j=0;j<k;j++){
    if(mp[i][j]=='#')continue;
    int res=0;
    for(int x=0;x<8;x++){
      if((i+dx[x]<n&&i+dx[x]>-1)&(j+dy[x]>-1&&j+dy[x]<k))res+=(mp[i+dx[x]][j+dy[x]]=='#');
    }
    mp[i][j]=(char)((int)res+'0');
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++)cout<<mp[i][j];
    cout<<endl;
  }
  return 0;
}
