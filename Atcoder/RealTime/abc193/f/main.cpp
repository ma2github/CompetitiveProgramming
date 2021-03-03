#include<bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
int main(){
  int n;
  scanf("%d\n",&n);
  std::vector<string> s(n);
  for(int i=0;i<n;i++)cin>>s[i];

  int ans=2*n*(n-1);//全てに辺が張られていた時の辺の本数

  const int N=n*n;
  const int S=N,T=N+1;
  mf_graph<int> g(N+2);

  const int dx[]={-1,1,0,0};
  const int dy[]={0,0,1,-1};
  const int INF=(int)1e9;

  auto vt=[&](int i,int j){
    return i*n+j;
  };

  auto type=[&](int i,int j){
    if(s[i][j]=='?')return 2;
    if(((i+j)%2==0)^(s[i][j]=='B'))return 1;
    return 0;
  };

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<4;k++){
        int ni=i+dx[k],nj=j+dy[k];
        if(ni<0 or ni>n-1 or nj<0 or nj>n-1)continue;
        g.add_edge(vt(i,j),vt(ni,nj),1);
      }
      if(type(i,j)==0)g.add_edge(S,vt(i,j),INF);
      if(type(i,j)==1)g.add_edge(vt(i,j),T,INF);
    }
  }

  ans-=g.flow(S,T);
  cout<<ans<<'\n';
  return 0;
}
