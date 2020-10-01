#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(n) for(int i=0;i<n;i++)
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  map<int,int>memo0,memo1;
  pair<pair<int,int>,pair<int,int>>cntmax0={{0,0},{0,0}},cntmax1={{0,0},{0,0}};
  rep(n){
    cin>>a[i];
    i%2?memo1[a[i]]++:memo0[a[i]]++;
    if(i%2){
      if(memo1[a[i]]>cntmax1.first.second)
        cntmax1={{a[i],memo1[a[i]]},cntmax1.first};
      else if(memo1[a[i]]>cntmax1.second.second)
        cntmax1={cntmax1.first,{a[i],memo1[a[i]]}};
    }
    if(i%2==0){
      if(memo0[a[i]]>cntmax0.first.second)
        cntmax0={{a[i],memo0[a[i]]},cntmax0.first};
      else if(memo0[a[i]]>cntmax0.second.second)
        cntmax0={cntmax0.first,{a[i],memo0[a[i]]}};
    }
  }
  int ans=n;
  if(a[0]!=a[1]&&memo0.size()==1&&memo1.size()==1)ans=0;
  else if(memo0.size()==1&&memo1.size()==1)ans=n/2;
  else {
    if(cntmax0.first.first!=cntmax1.first.first)ans-=cntmax0.first.second+cntmax1.first.second;
    else ans-=max(cntmax0.first.second+cntmax1.second.second,cntmax0.second.second+cntmax1.first.second);
  }
  cout<<ans<<endl;
  return 0;
}
