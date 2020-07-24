#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
/*繰り返し*/
#define rep1(n) for(ll i=0;i<n;++i)//n回repeat
#define rep2(i,n) for(ll i=0;i<n;++i)//n回repeat（変数指定）
#define rep3(i,a,b) for(ll i=a;i<b;++i)//a-bまでrepeat
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)//a-bまで公差cでrepeat（等差数列で使えそう）
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)//repeatまとめ
#define rrep1(n) for(ll i=(n);i--;)
#define rrep2(i,n) for(ll i=(n);i--;)
#define rrep3(i,a,b) for(ll i=(b);i-->(a);)
#define rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)//逆repeatまとめ
#define each1(i,a) for(auto&& i:a)
#define each2(x,y,a) for(auto&& [x,y]:a)
#define each3(x,y,z,a) for(auto&& [x,y,z]:a)
#define each(...) overload4(__VA_ARGS__,each3,each2,each1)(__VA_ARGS__)//配列の各要素の読み出し
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)//vectorの始めと終わりの読み取り
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)//逆イテレータの取得(rbegin：末尾,rend：頭）
#define sum(...) accumulate(all(__VA_ARGS__),0LL)//vectorの合計(int形で受け付けてしまうので，小数で扱いたい場合はdsumを使う)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)//小数で扱う(long long doubleなど)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
/*標準入力*/
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)//int型標準入力受付，以下LDまで同様
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
/*vector操作*/
#define Sort(a) sort(all(a))//昇順ソート
#define RSort(vec) sort(vec.begin(), vec.end(), greater<ll>())//降順ソート
#define Rev(a) reverse(all(a))//逆順
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type> name(__VA_ARGS__)//type型vectorの定義
#define VEC(type,name,size) vector<type> name(size);in(name)//type型vector(size指定)標準入力受付
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define IV(type,name,size) vector<pair<int, int>> name;for (int i = 0; i < size; i++) {int a_i;cin >> a_i; name.emplace_back(a_i,i);}//Indexつきvector（pair型Vector,(data,index)）
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
vector<ll> iota(ll n){ vector<ll> a(n); iota(a.begin(), a.end(), 0); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
map<ll,ll> factor_map(ull x){ map<ll,ll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans[i] = 1; while((x /= i) % i == 0) ans[i]++; } if(x != 1) ans[x] = 1; return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); unordered_map<T, ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
template<class T> map<T, ll> press_map(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); map<T, ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
int scan(){ return getchar(); }
void scan(int& a){ scanf("%d", &a); }
void scan(unsigned& a){ scanf("%u", &a); }
void scan(long& a){ scanf("%ld", &a); }
void scan(long long& a){ scanf("%lld", &a); }
void scan(unsigned long long& a){ scanf("%llu", &a); }
void scan(char& a){ do{ a = getchar(); }while(a == ' ' || a == '\n'); }
void scan(float& a){ scanf("%f", &a); }
void scan(double& a){ scanf("%lf", &a); }
void scan(long double& a){ scanf("%Lf", &a); }
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(float a){ printf("%.15f", a); }
void print(double a){ printf("%.15f", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }//cout<<t<<endl
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
inline ll __lg(ull __n){ return sizeof(ull) * __CHAR_BIT__  - 1 - __builtin_clzll(__n); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
/*判定出力*/
int first(bool i = true){ return out(i?"first":"second"); }//iがfirstか判断，以下同様
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }
/*vector探索*/
#define bSearch(v,k) binary_search(all(v),k)//ソートされた配列vの中の要素にkがあるか(boolean)
#define lowB(v,k) lower_bound(all(v),k)//ソートされた配列vの中の要素のうちk以上かつ最小のイテレータ
#define DLbetB(v,k) lowB(v,k)-v.begin()//先頭からの距離
#define DLbetE(v,k) v.end()-lowB(v,k)//末尾からの距離
#define uppB(v,k) upper_bound(all(v),k)//ソートされた配列vの中の要素のうちkより大きいかつ最小のイテレータ
#define DUbetB(v,k) uppB(v,k)-v.begin()//先頭からの距離
#define DUbetE(v,k) v.end()-uppB(v,k)//末尾からの距離
#define Cnt(v,k) count(all(v),k)//配列vの中で要素kが何個あるかを返す(size_t)
#define CntIf(v,l) count_if(all(v),l)//配列vの中で条件式(lambda式)を満たす個数を返す(ex.int num = count_if(v.begin(), v.end(), [](int i){return i % 3 == 0;});)
#define Sort2D(myVec,i) sort(myVec.begin(),myVec.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[i] < beta[i];});//i列めでソート
/*最大公約数*/
template <class T>
T vgcd(T m, T n) {
  return gcd(m, n);
}

template <class T, class... Args>
T vgcd(T a, Args... args) {
  return vgcd(a, vgcd(args...));
}
/*階乗*/
int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}
/*組み合わせnCk*/
ll comb(const ll N,const ll K){
  vector<vector<long long int> > v(N+1,vector<long long int>(N+1,0));
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
  return v[N][K];
}
deque<ll> deq;
ll dup;
/*クイックセレクト　ピボット値を中央値の中央値で求める（参考：https://ja.wikipedia.org/wiki/中央値の中央値）
選択アルゴリズムについては，http://www.flint.jp/blog/?entry=109*/
ll Median5(vector<ll> data,ll st,ll ed){
  if(st==ed)return data[st];
  else{
  for (int i = st+1; i <= ed; i++) {
    ll tmp = data[i];
    if (data[i - 1] > tmp) {
        int j = i;
        do {
            data[j] = data[j - 1];
            j--;
            if(j<=st)break;
        } while (data[j - 1] > tmp);
        data[j] = tmp;
    }
}
  ld endld=ld(ed);
  ld startld=ld(st);
  ld ev=ld(2);
  ll mid=ceil(ld(endld+startld)/(ld)ev);
  return data[mid];
}
}
ll Pivot(vector<ll> array,ll start,ll end){
  if(end-start<5)return Median5(array,start,end);
  else{
    ld endld=ld(end+1);
    ld startld=ld(start);
    ld dv=ld(5);
    ll n=ceil(ld(endld-startld)/(ld)dv);
    std::vector<ll> medians;
    rep(i,start,end+1,5){
      ll subStart=i;
      ll subEnd=min(i+4,end);
      ll median=Median5(array,subStart,subEnd);
      medians.push_back(median);
    }
    start=0;
    end=n-1;
    return Pivot(medians,start,end);
  }
}

ll Partition(vector<ll> array,ll start,ll end,ll pivot){
  ll pivotIndex=start;
  deq.push_back(pivot);
  dup=0;
  rep(i,start,end+1){if(array[i]<pivot){deq.push_front(array[i]);pivotIndex++;}else if(array[i]>pivot)deq.push_back(array[i]);else dup++;}
  return pivotIndex;
}

ll Select(vector<ll> array1,ll k1,ll start,ll end){
  ll pivotIndex,pivot;
  do{
    pivot=Pivot(array1,start,end);
    deq.clear();
    pivotIndex=Partition(array1,start,end,pivot);
    if(pivotIndex<=k1-1&&k1-1<pivotIndex+dup)break;
    size_t size=deq.size();
    ll index=start;
    rep(i,size){if(deq[i]==pivot){rep(dup){array1[index]=pivot;index++;}}else {array1[index]=deq[i];index++;}}
    if(pivotIndex<k1-1)start=pivotIndex+1;
    else if(pivotIndex>k1-1)end=pivotIndex-1;
  }while(pivotIndex>k1-1||pivotIndex+dup<=k1-1);
  return pivot;
}
/*ページのソースを表示->command+F->問題文　で問題文コピペする

*/
//deque<ll> deq;//両端キュー使う，先頭と末尾へのアクセスが早い
signed main(){
    /*以下コード*/
    /*別解：クイックセレクトを用いることにより（理論上）O(n)でできるバージョン*/
    LL(n,m);//n種類のケーキ，そのうちからm個選ぶ
    VV(ll,a,n,3);//n種類のケーキの綺麗さ，美味しさ，人気度
    if(m==0)out(0);//1つも食べない場合は当然0
    else{
      ll ans=0;//答えの初期値（絶対値の合計なので答えは0以上）
    rep(i,8){//どのパラメータの符号を反転させるかで2^3=8通り総当たり
      ll sm=0;//そのパターンにおける合計値
      std::vector<ll> b(n,0);//そのパターンにおける各ケーキの全てのパラメータの合計
      rep(j,3)rep(k,n)if((i>>j)&1)b[k]+=a[k][j];else b[k]-=a[k][j];//各パラメータに対して，もしそのパラメータに対して1が立っていればそのパラメータは符号をそのままに加算する，そうでなければ符号を反転して加算する
      ll bb=b.begin()-b.begin();
      ll be=b.end()-b.begin()-1;
      ll limit=Select(b,n-m+1,bb,be);//O(n)の選択アルゴリズム，m番目に大きい=n-m+1番目に小さい　処理が複雑なので実用的ではない（nが巨大な範囲で有効）
      ll cnt=0;
      rep(l,n)if(limit<b[l]){sm+=b[l];cnt++;}//大きい順にm個足し合わせる
      sm+=limit*(m-cnt);//閾値と同じ値で何個も連なっている可能性があるのでそこだけ別計算（それより小さい値は足されることがない）
      chmax(ans,sm);//現在の暫定の答えと比較してこのパターンの合計の方が大きければ答えをsmに更新する
    }
    out(ans);//答えの出力
  }
}
