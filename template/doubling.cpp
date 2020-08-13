/*
参考：http://satanic0258.hatenablog.com/entry/2017/02/23/222647

使える場所：1回遷移した先が明確にわかる時

目的：
・ある数XのQ乗を求める
・根付き木において、ある頂点vのQ個上の親を知る
・ある地点からQ回進んだ先を求める
*/
//int N; // 全体の要素数
//int Q;//試行回数
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll doubling(const ll N,const ll Q,vector<ll> a){//cin>>N>>Q;//標準入力から要素数と試行回数を受け取る場合
ll LOG_Q = floor(log2(Q))+1;

// next[k][i]で、i番目の要素の「2^k個次の要素」を指す
// (なお、i番目の要素に対して「2^k個次の要素」が存在しないとき、
//  next[k][i]が指し示す要素番号を-1とします)
std::vector<std::vector<ll>> next(LOG_Q + 1, std::vector<ll>(N));
//ll a[N];//各要素の次の行き先

// next[0]を計算
for (int i = 0; i < N; ++i){
    next[0][i] = a[i];
}

// nextを計算
for (ll k = 0; k < LOG_Q; ++k){
    for (int i = 0; i < N; ++i){
        if (next[k][i] == -1) {
            // 2^k個次に要素が無い時、当然2^(k+1)個次にも要素はありません
            next[k + 1][i] = -1;
        }
        else {
            // 「2^k個次の要素」の2^k個次の要素は、2^(k+1)個次の要素です
            next[k + 1][i] = next[k][next[k][i]];
        }
    }
}

// ----ここまで準備----

// p番目の要素の「Q個次の要素」を求めることを考えます
ll p=0;
for (ll k = LOG_Q - 1; k >= 0; --k){
    if (p == -1) {
        // pがすでに存在しない要素を指していたら、
        // それ以降で存在する要素を指すことはないためループを抜けます
        break;
    }
    if ((Q >> k) & 1) {//ex(Q=5)5=101(2)であり，2^2+2^0回進むことを表す
        // Qを二進展開した際、k番目のビットが立っていたら、
        // pの位置を2^kだけ次にずらします
        p = next[k][p];
    }
}
return p;//ここでのpが最終的な答えになる
}
