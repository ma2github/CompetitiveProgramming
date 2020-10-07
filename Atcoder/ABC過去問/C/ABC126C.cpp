#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
int main(){
  int n,k;
  cin>>n>>k;
  ld d=1.0/n;
  ld ans=0;n++;
  while(--n){
    int ml=1;
    ld p=1;
    while(n*ml<k)ml*=2,p*=0.5;
    ans+=d*p;
  }
  printf("%.15Lf\n",ans);
  return 0;
}
