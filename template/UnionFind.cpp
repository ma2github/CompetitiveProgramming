ll par[NLGLMT];
ll height[NLGLMT];

void UnionInit(ll n){
  rep(n){
    par[i]=i;//初めは全ての頂点が根である
    height[i]=0;
  }
}

ll root(ll x){//木の根を求める
  if(par[x]==x)return x;//根
  else return par[x]=root(par[x]);//根でない場合経路圧縮（根に直接繋ぎ直す）
}

bool same(ll x,ll y){//x,yが同じ木に属するか判定
  return root(x)==root(y);
}

void unite(ll x,ll y){//x,yの属する集合を併合
  x=root(x);
  y=root(y);
  if(x==y)return;//同じ集合なら何もしない
  if(height[x]<height[y])par[x]=y;//高い方の親に繋ぐ
  else{
    par[y]=x;//高い方の親に繋ぐ
    if(height[x]==height[y])height[x]++;//新しい親+元の木で高さ+1
  }
}
