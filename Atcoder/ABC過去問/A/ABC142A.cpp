#include<bits/stdc++.h>
using namespace std;
int main(){
long long n;
  cin>>n;
  (n&1)?cout<<(long double)((n+1)/2)/(long double)n:cout<<0.5;
}
