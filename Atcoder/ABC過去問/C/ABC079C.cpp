#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  const char op[]={'+','-'};
  for(int i=0;i<8;i++){
    int res=s[0]-'0';
    for(int j=0;j<3;j++)(i>>j)&1?res-=s[j+1]-'0':res+=s[j+1]-'0';
    if(res==7){
      cout<<s[0];
      for(int j=0;j<3;j++)cout<<op[(i>>j)&1]<<s[j+1];
      cout<<"=7"<<endl;
      return 0;
    }
  }
  return 0;
}
