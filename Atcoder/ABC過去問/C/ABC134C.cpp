#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  vector<long long>a(n);
  pair<pair<long long,long long>,long long>amax={{0,-1},-1};
  for(long long i=0;i<n;i++){
    cin>>a[i];
    if(amax.first.first<a[i])amax={{a[i],i},amax.first.first};
    else if(amax.second<a[i])amax={amax.first,a[i]};
  }
  for(long long i=0;i<n;i++)i==amax.first.second?cout<<amax.second:cout<<amax.first.first,cout<<endl;
  return 0;
}
