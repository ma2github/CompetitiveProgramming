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
const ll LPLMT=10000000;//O(n)のloop上限
const ll NLGLMT=200000;//O(NlogN)のloop上限（これで指定されたfor文の中にO(logN)の処理を書く）
const ll N2LMT=3000;//O(n^2)のloop上限
const ll N3LMT=100;//O(n^3)のloop上限
const ll N4LMT=50;//O(n^4)のloop上限
const ll TNLMT=20;//O(2^n)のloop上限（実際この計算量になるのは全探索くらいなので，この値自体を使うことはなさそう）（オーダの参考程度に）
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
//#define debug(...) void(0)
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
#define Sort2D(myVec,i) sort(myVec.begin(),myVec.end(),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[i] < beta[i];});//i列めでソート
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
ll facctorialMethod(ll k){
    int sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        //sum%=MOD;//あまりを出力せよ問題の時はこれもやる
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
/*逆元　あまりの割り算をするときにこいつをかける*/
// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a,ll m){
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
/*ダブリング*/
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
/*素数判定*/
bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


/*ページのソースを表示->command+F->問題文　で問題文コピペする

*/
enum {
    NOTFOUND = 0xFFFFFFFFFFFFFFFFLLU
};

class SuccinctBitVector {
private:
    const ll size;    // ビットベクトルのサイズ
    static const ll blockBitNum = 16;
    static const ll LEVEL_L = 512;
    static const ll LEVEL_S = 16;

    std::vector<ll> L;   // 大ブロック
    std::vector<uint16_t> S;   // 小ブロック
    std::vector<uint16_t> B;   // ビットベクトル

    ll numOne = 0;       // 1bitの数

public:
    explicit SuccinctBitVector(const ll n) : size(n) {
        const ll s = (n + blockBitNum - 1) / blockBitNum + 1;   // ceil(n, blockSize)
        this->B.assign(s, 0);
        this->L.assign(n / LEVEL_L + 1, 0);
        this->S.assign(n / LEVEL_S + 1, 0);
    }

    // B[pos] = bit
    void setBit(const ll bit, const ll pos){
        assert(bit == 0 or bit == 1);
        assert(pos < this->size);

        const ll blockPos = pos / blockBitNum;
        const ll offset = pos % blockBitNum;
        if (bit == 1) { B.at(blockPos) |= (1LLU << offset); }
        else          { B.at(blockPos) &= (~(1LLU << offset)); }
    }

    // B[pos]
    ll access(const ll pos) {
        assert(pos < this->size);
        const ll blockPos = pos / blockBitNum;
        const ll offset   = pos % blockBitNum;
        return ((B.at(blockPos) >> offset) & 1);
    }

    void build() {
        ll num = 0;
        for (ll i = 0; i <= size; i++){
            if (i % LEVEL_L == 0) {
                L.at(i / LEVEL_L) = num;
            }
            if (i % LEVEL_S == 0) {
                S.at(i / LEVEL_S) = num - L.at(i / LEVEL_L);
            }
            if (i != size and i % blockBitNum == 0) {
                num += this->popCount(this->B.at(i / blockBitNum));
            }
        }
        this-> numOne = num;
    }

    // B[0, pos)のbitの数
    ll rank(const ll bit, const ll pos) {
        assert(bit == 0 or bit == 1);
        assert(pos <= this->size);

        if (bit) {
            return L[pos / LEVEL_L] + S[pos / LEVEL_S] + popCount(B[pos / blockBitNum] & ((1 << (pos % blockBitNum)) - 1));
        }
        else {
            return pos - rank(1, pos);
        }
    }

    // rank番目のbitの位置 + 1(rankは1-origin)
    ll select(const ll bit, const ll rank) {
        assert(bit == 0 or bit == 1);
        assert(rank > 0);
        if (bit == 0 and rank > this->size - this-> numOne) { return NOTFOUND; }
        if (bit == 1 and rank > this-> numOne)              { return NOTFOUND; }

        // 大ブロックL内を検索
        ll large_idx = 0;
        {
            ll left = 0;
            ll right = L.size();
            while (right - left > 1) {
                ll mid = (left + right) / 2;
                ll r = L.at(mid);
                r = (bit) ? r : mid * LEVEL_L - L.at(mid);

                if (r < rank) {
                    left = mid;
                    large_idx = mid;
                } else {
                    right = mid;
                }
            }
        }

        // 小ブロックS内を検索
        ll small_idx = (large_idx * LEVEL_L) / LEVEL_S;
        {
            ll left = (large_idx * LEVEL_L) / LEVEL_S;
            ll right = std::min(((large_idx  + 1) * LEVEL_L) / LEVEL_S, (ll)S.size());
            while (right - left > 1) {
                ll mid = (left + right) / 2;
                ll r = L.at(large_idx) + S.at(mid);
                r = (bit) ? r :mid * LEVEL_S - r;

                if (r < rank) {
                    left = mid;
                    small_idx = mid;
                } else {
                    right = mid;
                }
            }
        }

        // Bをブロック単位で順番に探索
        ll rank_pos = 0;
        {
            const ll begin_block_idx = (small_idx * LEVEL_S) / blockBitNum;
            ll total_bit = L.at(large_idx) + S.at(small_idx);
            if (bit == 0) {
                total_bit = small_idx * LEVEL_S - total_bit;
            }
            for (ll i = 0;; ++i) {
                ll b = popCount(B.at(begin_block_idx + i));
                if (bit == 0) {
                    b = blockBitNum - b;
                }
                if (total_bit + b >= rank) {
                    ll block = (bit) ? B.at(begin_block_idx + i) : ~B.at(begin_block_idx + i);
                    rank_pos = (begin_block_idx + i) * blockBitNum + selectInBlock(block, rank - total_bit);
                    break;
                }
                total_bit += b;
            }
        }

        return rank_pos + 1;
    }

    ll getNumOne() const {
        return numOne;
    }

    void debug() {
        std::cout << "LEVEL_L(" << L.size() << ")" << std::endl;
        for (ll i = 0 ; i < L.size(); ++i) {
            std::cout << L.at(i) << ", ";
        }
        std::cout << std::endl;
        std::cout << "LEVEL_S(" << S.size() << ")" << std::endl;
        for (ll i = 0 ; i < S.size(); ++i) {
            std::cout << S.at(i) << ", ";
        }
        std::cout << std::endl;
    }

private:
    ll popCount(ll x) {
        x = (x & 0x5555555555555555ULL) + ((x >> 1) & 0x5555555555555555ULL);
        x = (x & 0x3333333333333333ULL) + ((x >> 2) & 0x3333333333333333ULL);
        x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
        x = x + (x >>  8);
        x = x + (x >> 16);
        x = x + (x >> 32);
        return x & 0x7FLLU;
    }

    ll selectInBlock(ll x, ll rank) {
        ll x1 = x - ((x & 0xAAAAAAAAAAAAAAAALLU) >> 1);
        ll x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> 2) & 0x3333333333333333LLU);
        ll x3 = (x2 + (x2 >> 4)) & 0x0F0F0F0F0F0F0F0FLLU;

        ll pos = 0;
        for (;;  pos += 8){
            ll rank_next = (x3 >> pos) & 0xFFLLU;
            if (rank <= rank_next) break;
            rank -= rank_next;
        }

        ll v2 = (x2 >> pos) & 0xFLLU;
        if (rank > v2) {
            rank -= v2;
            pos += 4;
        }

        ll v1 = (x1 >> pos) & 0x3LLU;
        if (rank > v1){
            rank -= v1;
            pos += 2;
        }

        ll v0  = (x >> pos) & 0x1LLU;
        if (v0 < rank){
            rank -= v0;
            pos += 1;
        }

        return pos;
    }
};
class WaveletMatrix {
private:
    std::vector<SuccinctBitVector> bit_arrays;
    std::vector<ll> begin_one;                    // 各bitに着目したときの1の開始位置
    std::map<ll, ll> begin_alphabet;        // 最後のソートされた配列で各文字の開始位置
    std::vector<std::vector<ll>> cumulative_sum;  // 各bitに着目したときの累積和

    ll size;                                 // 与えられた配列のサイズ
    ll maximum_element;                      // 文字数
    ll bit_size;                             // 文字を表すのに必要なbit数

public:
    WaveletMatrix (const std::vector<ll> &array) {
        assert(array.size() > 0);
        size = array.size();
        maximum_element =  *max_element(array.begin(), array.end()) + 1;
        bit_size = get_num_of_bit(maximum_element);
        if (bit_size == 0) {
            bit_size = 1;
        }

        for (ll i = 0; i < bit_size; ++i) {
            SuccinctBitVector sv(size);
            bit_arrays.push_back(sv);
        }
        this->begin_one.resize(bit_size);
        this->cumulative_sum.resize(bit_size + 1, std::vector<ll>(size + 1, 0));

        for (ll j = 0; j < array.size(); ++j) {
            this->cumulative_sum.at(0).at(j + 1) = this->cumulative_sum.at(0).at(j) + array[j];
        }

        std::vector<ll> v(array);
        for (ll i = 0; i < bit_size; ++i) {

            std::vector<ll> temp;
            // 0をtempにいれてく
            for (ll j = 0; j < v.size(); ++j) {
                ll c = v.at(j);
                ll bit = (c >> (bit_size - i - 1)) & 1;  //　上からi番目のbit
                if (bit == 0) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(0, j);
                }
            }

            this->begin_one.at(i) = temp.size();

            // 1をtempにいれてく
            for (ll j = 0; j < v.size(); ++j) {
                ll c = v.at(j);
                ll bit = (c >> (bit_size - i - 1)) & 1;  //　上からi番目のbit
                if (bit == 1) {
                    temp.push_back(c);
                    bit_arrays.at(i).setBit(1, j);
                }
            }

            for (ll j = 0; j < temp.size(); ++j) {
                this->cumulative_sum.at(i + 1).at(j + 1) = this->cumulative_sum.at(i + 1).at(j) + temp.at(j);
            }

            bit_arrays.at(i).build();
            v = temp;
        }

        // ソートされた配列内での各文字の位置を取得
        for (int i = v.size() - 1; i >= 0; --i) {
            this->begin_alphabet[v.at(i)] = i;
        }
    }

    // v[pos]
    ll access(ll pos) {
        if (pos >= this->size) { return NOTFOUND; }

        ll c = 0;
        for (ll i = 0; i < bit_arrays.size(); ++i) {
            ll bit = bit_arrays.at(i).access(pos);   // もとの数値のi番目のbit
            c = (c <<= 1) | bit;
            pos = bit_arrays.at(i).rank(bit, pos);
            if (bit) {
                pos += this->begin_one.at(i);
            }
        }
        return c;
    }

    // i番目のcの位置 + 1を返す。rankは1-origin
    ll select(ll c, ll rank) {
        assert(rank > 0);
        if (c >= maximum_element) {
            return NOTFOUND;
        }
        if (this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return NOTFOUND;
        }

        ll index = this->begin_alphabet.at(c) + rank;
        for (ll i = 0; i < bit_arrays.size(); ++i){
            ll bit = ((c >> i) & 1);      // 下からi番目のbit
            if (bit == 1) {
                index -= this->begin_one.at(bit_size - i - 1);
            }
            index = this->bit_arrays.at(bit_size - i - 1).select(bit, index);
        }
        return index;
    }

    // v[begin_pos, end_pos)で最大値のindexを返す
    ll maxRange(ll begin_pos, ll end_pos) {
        return quantileRange(begin_pos, end_pos, end_pos - begin_pos - 1);
    }

    // v[begin_pos, end_pos)で最小値のindexを返す
    ll minRange(ll begin_pos, ll end_pos) {
        return quantileRange(begin_pos, end_pos, 0);
    }

    // v[begin_pos, end_pos)でk番目に小さい数値のindexを返す(kは0-origin)
    // つまり小さい順に並べてk番目の値
    ll quantileRange(ll begin_pos, ll end_pos, ll k) {
        if ((end_pos > size || begin_pos >= end_pos) || (k >= end_pos - begin_pos)) {
            return NOTFOUND;
        }

        ll val = 0;
        for (ll i = 0; i < bit_size; ++i) {
            const ll num_of_zero_begin = bit_arrays.at(i).rank(0, begin_pos);
            const ll num_of_zero_end = bit_arrays.at(i).rank(0, end_pos);
            const ll num_of_zero = num_of_zero_end - num_of_zero_begin;     // beginからendまでにある0の数
            const ll bit = (k < num_of_zero) ? 0 : 1;                       // k番目の値の上からi番目のbitが0か1か

            if (bit) {
                k -= num_of_zero;
                begin_pos = this->begin_one.at(i) + begin_pos - num_of_zero_begin;
                end_pos = this->begin_one.at(i) + end_pos - num_of_zero_end;
            }
            else {
                begin_pos = num_of_zero_begin;
                end_pos = num_of_zero_begin + num_of_zero;
            }

            val = ((val << 1) | bit);
        }

        ll left = 0;
        for (ll i = 0; i < bit_size; ++i) {
            const ll bit = (val >> (bit_size - i - 1)) & 1;  // 上からi番目のbit
            left = bit_arrays.at(i).rank(bit, left);               // cのi番目のbitと同じ数値の数
            if (bit) {
                left += this->begin_one.at(i);
            }
        }

        const ll rank = begin_pos + k - left + 1;
        return select(val, rank) - 1;
    }

    // v[0, pos)のcの数
    ll rank(ll c, ll pos) {
        assert(pos < size);
        if (c >= maximum_element) {
            return 0;
        }
        if (this->begin_alphabet.find(c) == this->begin_alphabet.end()) {
            return 0;
        }

        for (ll i = 0; i < bit_size; ++i) {
            ll bit = (c >> (bit_size - i - 1)) & 1;  // 上からi番目のbit
            pos = bit_arrays.at(i).rank(bit, pos);         // cのi番目のbitと同じ数値の数
            if (bit) {
                pos += this->begin_one.at(i);
            }
        }

        ll begin_pos = this->begin_alphabet.at(c);
        return pos - begin_pos;
    }

    // v[begin_pos, end_pos)で[min, max)に入る値の個数
    ll rangeFreq(ll begin_pos, ll end_pos, ll min_c, ll max_c) {
        if ((end_pos > size || begin_pos >= end_pos) || (min_c >= max_c) || min_c >= maximum_element) {
            return 0;
        }

        const auto maxi_t = rankAll(max_c, begin_pos, end_pos);
        const auto mini_t = rankAll(min_c, begin_pos, end_pos);
        return std::get<1>(maxi_t) - std::get<1>(mini_t);
    }

    // v[0, pos)でcより小さい文字の数
    ll rankLessThan(ll c, ll begin, ll end) {
        auto t = rankAll(c, begin, end);
        return std::get<1>(t);
    }

    // v[0, pos)でcより大きい文字の数
    ll rankMoreThan(ll c, ll begin, ll end) {
        auto t = rankAll(c, begin, end);
        return std::get<2>(t);
    }

    // v[begin, end)で(cと同じ値の数、cより小さい値の数、cより大きい値の数)を求める
    std::tuple<ll, ll, ll> rankAll(const ll c, ll begin, ll end) {
        assert(end <= size);
        const ll num = end - begin;

        if (begin >= end) {
            return std::make_tuple(0, 0, 0);
        }
        if (c >= maximum_element || end == 0) {
            return std::make_tuple(0, num, 0);
        }

        ll rank_less_than = 0, rank_more_than = 0;
        for (size_t i = 0; i < bit_size && begin < end; ++i) {
            const ll bit = (c >> (bit_size - i - 1)) & 1;

            const ll rank0_begin = this->bit_arrays.at(i).rank(0, begin);
            const ll rank0_end = this->bit_arrays.at(i).rank(0, end);
            const ll rank1_begin = begin - rank0_begin;
            const ll rank1_end = end - rank0_end;

            if (bit) {
                rank_less_than += (rank0_end - rank0_begin);    // i番目のbitが0のものは除外される
                begin = this->begin_one.at(i) + rank1_begin;
                end = this->begin_one.at(i) + rank1_end;
            } else {
                rank_more_than += (rank1_end - rank1_begin);    // i番目のbitが1のものは除外される
                begin = rank0_begin;
                end = rank0_end;
            }
        }

        const ll rank = num - rank_less_than - rank_more_than;
        return std::make_tuple(rank, rank_less_than, rank_more_than);
    }

    // T[s, e)で出現回数が多い順にk個の(値，頻度)を返す
    // 頻度が同じ場合は値が小さいものが優先される
    std::vector<std::pair<ll, ll>> topk(ll s, ll e, ll k) {
        assert(s < e);
        std::vector<std::pair<ll, ll>> result;

        // (頻度，深さ，値)の順でソート
        auto c = [](const std::tuple<ll, ll, ll, ll, ll> &l, const std::tuple<ll, ll, ll, ll, ll> &r) {
            // width
            if (std::get<0>(l) != std::get<0>(r)) {
                return std::get<0>(l) < std::get<0>(r);
            }
            // depth
            if (std::get<3>(l) != std::get<3>(r)) {
                return std::get<3>(l) > std::get<3>(r);
            }
            // value
            if (std::get<4>(l) != std::get<4>(r)) {
                return std::get<4>(l) > std::get<4>(r);
            }
            return true;
        };

        std::priority_queue<std::tuple<ll, ll, ll, ll, ll>, std::vector<std::tuple<ll, ll, ll, ll, ll>>, decltype(c)> que(c);  // width, left, right, depth, value
        que.push(std::make_tuple(e - s, s, e, 0, 0));

        while (not que.empty()) {
            auto element = que.top(); que.pop();
            ll width, left, right, depth, value;
            std::tie(width, left, right, depth, value) = element;

            if (depth >= this->bit_size) {
                result.emplace_back(std::make_pair(value, right - left));
                if (result.size() >= k) {
                    break;
                }
                continue;
            }

            // 0
            const ll left0 = this->bit_arrays.at(depth).rank(0, left);
            const ll right0 = this->bit_arrays.at(depth).rank(0, right);
            if (left0 < right0) {
                que.push(std::make_tuple(right0 - left0, left0, right0, depth + 1, value));
            }

            // 1
            const ll left1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, left);
            const ll right1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, right);
            if (left1 < right1) {
                que.push(std::make_tuple(right1 - left1, left1, right1, depth + 1, value | (1 << (bit_size - depth - 1))));
            }
        }

        return result;
    };

    // T[begin_pos, end_pos)でx <= c < yを満たすcの和を返す
    ll rangeSum(const ll begin, const ll end, const ll x, const ll y) {
        return rangeSum(begin, end, 0, 0, x, y);
    }

    // T[begin_pos, end_pos)でx <= c < yを満たす最大のcを返す
    ll prevValue(const ll begin_pos, const ll end_pos, const ll x, ll y) {
        assert(end_pos <= size);
        const ll num = end_pos - begin_pos;

        if (x >= y or y == 0) {
            return NOTFOUND;
        }
        if (y > maximum_element) {
            y = maximum_element;
        }

        if (begin_pos >= end_pos) {
            return NOTFOUND;
        }
        if (x >= maximum_element || end_pos == 0) {
            return NOTFOUND;
        }

        y--; // x <= c <= yにする

        std::stack<std::tuple<ll, ll, ll, ll, bool>> s;   // (begin, end, depth, c, tight)
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

        while (not s.empty()) {
            ll b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top(); s.pop();

            if (depth == bit_size) {
                if (c >= x) {
                    return c;
                }
                continue;
            }

            const ll bit = (y >> (bit_size - depth - 1)) & 1;

            const ll rank0_begin = this->bit_arrays.at(depth).rank(0, b);
            const ll rank0_end = this->bit_arrays.at(depth).rank(0, e);
            const ll rank1_begin = b - rank0_begin;
            const ll rank1_end = e - rank0_end;

            // d番目のbitが0のものを使う
            const ll b0 = rank0_begin;
            const ll e0 = rank0_end;
            if (b0 != e0) { // 範囲がつぶれてない
                const ll c0 = ((c << 1) | 0);
                s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight and bit == 0));
            }

            // d番目のbitが1のものを使う
            const ll b1 = this->begin_one.at(depth) + rank1_begin;
            const ll e1 = this->begin_one.at(depth) + rank1_end;
            if (b1 != e1) {
                if (not tight or bit == 1) {
                    const auto c1 = ((c << 1) | 1);
                    s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight));
                }
            }
        }

        return NOTFOUND;
    }

    // T[begin_pos, end_pos)でx <= c < yを満たす最小のcを返す
    ll nextValue(const ll begin_pos, const ll end_pos, const ll x, const ll y) {
        assert(end_pos <= size);
        const ll num = end_pos - begin_pos;

        if (x >= y or y == 0) {
            return NOTFOUND;
        }

        if (begin_pos >= end_pos) {
            return NOTFOUND;
        }
        if (x >= maximum_element || end_pos == 0) {
            return NOTFOUND;
        }

        std::stack<std::tuple<ll, ll, ll, ll, bool>> s;   // (begin, end, depth, c, tight)
        s.emplace(std::make_tuple(begin_pos, end_pos, 0, 0, true));

        while (not s.empty()) {
            ll b, e, depth, c;
            bool tight;
            std::tie(b, e, depth, c, tight) = s.top(); s.pop();

            if (depth == bit_size) {
                if (c < y) {
                    return c;
                }
                continue;
            }

            const ll bit = (x >> (bit_size - depth - 1)) & 1;

            const ll rank0_begin = this->bit_arrays.at(depth).rank(0, b);
            const ll rank0_end = this->bit_arrays.at(depth).rank(0, e);
            const ll rank1_begin = b - rank0_begin;
            const ll rank1_end = e - rank0_end;

            // d番目のbitが1のものを使う
            const ll b1 = this->begin_one.at(depth) + rank1_begin;
            const ll e1 = this->begin_one.at(depth) + rank1_end;
            if (b1 != e1) {
                const auto c1 = ((c << 1) | 1);
                s.emplace(std::make_tuple(b1, e1, depth + 1, c1, tight and bit == 1));
            }

            // d番目のbitが0のものを使う
            const ll b0 = rank0_begin;
            const ll e0 = rank0_end;
            if (b0 != e0) {
                if (not tight or bit == 0) {
                    const ll c0 = ((c << 1) | 0);
                    s.emplace(std::make_tuple(b0, e0, depth + 1, c0, tight));
                }
            }
        }

        return NOTFOUND;
    }

    // T[s1, e1)とT[s2, e2)に共通して出現する要素を求める
    std::vector<std::tuple<ll, ll, ll>> intersect(ll _s1, ll _e1, ll _s2, ll _e2) {
        assert(_s1 < _e1);
        assert(_s2 < _e2);

        std::vector<std::tuple<ll, ll, ll>> intersection;

        std::queue<std::tuple<ll, ll, ll, ll, ll, ll>> que; // s1, e1, s2, e2, depth, value
        que.push(std::make_tuple(_s1, _e1, _s2, _e2, 0, 0));
        while (not que.empty()) {
            auto e = que.front(); que.pop();
            ll s1, e1, s2, e2, depth, value;
            std::tie(s1, e1, s2, e2, depth, value) = e;

            if (depth >= this->bit_size) {
                intersection.emplace_back(std::make_tuple(value, e1 - s1, e2 - s2));
                continue;
            }

            // 0
            ll s1_0 = this->bit_arrays.at(depth).rank(0, s1);
            ll e1_0 = this->bit_arrays.at(depth).rank(0, e1);
            ll s2_0 = this->bit_arrays.at(depth).rank(0, s2);
            ll e2_0 = this->bit_arrays.at(depth).rank(0, e2);

            if (s1_0 != e1_0 and s2_0 != e2_0) {
                que.push(std::make_tuple(s1_0, e1_0, s2_0, e2_0, depth + 1, value));
            }

            // 1
            ll s1_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s1);
            ll e1_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e1);
            ll s2_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, s2);
            ll e2_1 = this->begin_one.at(depth) + this->bit_arrays.at(depth).rank(1, e2);

            if (s1_1 != e1_1 and s2_1 != e2_1) {
                que.push(std::make_tuple(s1_1, e1_1, s2_1, e2_1, depth + 1, value | (1 << bit_size - depth - 1)));
            }
        }

        return intersection;
    };

private:
    ll get_num_of_bit(ll x) {
        if (x == 0) return 0;
        x--;
        ll bit_num = 0;
        while (x >> bit_num) {
            ++bit_num;
        }
        return bit_num;
    }

    ll rangeSum(const ll begin, const ll end, const ll depth, const ll c, const ll x, const ll y) {
        if (begin == end) {
            return 0;
        }

        if (depth == bit_size) {
            if (x <= c and c < y) {
                return c * (end - begin);   // 値 * 頻度
            }
            return 0;
        }

        const ll next_c = ((ll)1 << (bit_size - depth - 1)) | c;                   // 上からdepth番目のbitを立てる
        const ll all_one_c = (((ll)1 << (bit_size - depth - 1)) - 1) | next_c;     // depth以降のbitをたてる(これ以降全部1を選んだときの値)
        if(all_one_c < x or y <= c) {
            return 0;
        }

        // [begin, pos)のすべての要素は[x, y)
        if (x <= c and all_one_c < y) {
            return this->cumulative_sum.at(depth).at(end) - this->cumulative_sum.at(depth).at(begin);
        }

        const ll rank0_begin = this->bit_arrays.at(depth).rank(0, begin);
        const ll rank0_end = this->bit_arrays.at(depth).rank(0, end);
        const ll rank1_begin = begin - rank0_begin;
        const ll rank1_end = end - rank0_end;

        return rangeSum(rank0_begin, rank0_end, depth + 1, c, x, y) +
               rangeSum(this->begin_one.at(depth) + rank1_begin, this->begin_one[depth] + rank1_end, depth + 1, next_c, x, y);
    }
};
//ceil()//切り上げ
//floor()//切り捨て
//round()//四捨五入
//deque<ll> deq;//両端キュー使う，先頭と末尾へのアクセスが早い
using std::map;
map<ll,ll>memo,f;//<キー，その要素＞，キーの検索が早い，キーは昇順にソートされる
signed main(){
    /*以下コード*/
    std::vector<pll> v;
    LL(n,q);
    std::vector<ll> ans(q,0);
    rep(n){
      LL(ci);
      f[ci]++;
      if(f[ci]>1)v.push_back(mp(memo[ci],i+1));
      memo[ci]=i+1;
    }
    Sort(v);
    std::vector<ll> map(500001,0);
    each(i,v)map[i.first]=i.second;
    //rep(15)out(map[i]);
    WaveletMatrix tree(map);
    rep(q){
      LL(li,ri);
      ll len=ri-li+1;
      ll cnt=tree.rangeFreq(li,ri+1,li,ri+1);
      ans[i]=len-cnt;
    }
    rep(q)out(ans[i]);
}
