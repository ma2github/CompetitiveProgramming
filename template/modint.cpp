/*
ref:https://github.com/tatyam-prime/kyopro_library/blob/master/Modint.cpp
*/
constexpr unsigned Mod = MOD;
struct Modint{
    unsigned num = 0;
    constexpr Modint() noexcept {}
    constexpr Modint(const Modint &x) noexcept : num(x.num){}
    inline constexpr operator ll() const noexcept { return num; }
    inline constexpr Modint& operator+=(Modint x) noexcept { num += x.num; if(num >= Mod) num -= Mod; return *this; }
    inline constexpr Modint& operator++() noexcept { if(num == Mod - 1) num = 0; else num++; return *this; }
    inline constexpr Modint operator++(int) noexcept { Modint ans(*this); operator++(); return ans; }
    inline constexpr Modint operator-() const noexcept { return Modint(0) -= *this; }
    inline constexpr Modint operator-(Modint x) const noexcept { return Modint(*this) -= x; }
    inline constexpr Modint& operator-=(Modint x) noexcept { if(num < x.num) num += Mod; num -= x.num; return *this; }
    inline constexpr Modint& operator--() noexcept { if(num == 0) num = Mod - 1; else num--; return *this; }
    inline constexpr Modint operator--(int) noexcept { Modint ans(*this); operator--(); return ans; }
    inline constexpr Modint& operator*=(Modint x) noexcept { num = ull(num) * x.num % Mod; return *this; }
    inline constexpr Modint& operator/=(Modint x) noexcept { return operator*=(x.inv()); }
    template<class T> constexpr Modint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(Mod); if(y < 0) y += Mod; num = unsigned(y);
    }
    template<class T> inline constexpr Modint operator+(T x) const noexcept { return Modint(*this) += x; }
    template<class T> inline constexpr Modint& operator+=(T x) noexcept { return operator+=(Modint(x)); }
    template<class T> inline constexpr Modint operator-(T x) const noexcept { return Modint(*this) -= x; }
    template<class T> inline constexpr Modint& operator-=(T x) noexcept { return operator-=(Modint(x)); }
    template<class T> inline constexpr Modint operator*(T x) const noexcept { return Modint(*this) *= x; }
    template<class T> inline constexpr Modint& operator*=(T x) noexcept { return operator*=(Modint(x)); }
    template<class T> inline constexpr Modint operator/(T x) const noexcept { return Modint(*this) /= x; }
    template<class T> inline constexpr Modint& operator/=(T x) noexcept { return operator/=(Modint(x)); }
    inline constexpr Modint inv() const noexcept { ll x = 0, y = 0; extgcd(num, Mod, x, y); return x; }
    static inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
    inline constexpr Modint pow(ull x) const noexcept { Modint ans = 1, cnt = *this; while(x){ if(x & 1) ans *= cnt; cnt *= cnt; x /= 2; } return ans; }
};
std::istream& operator>>(std::istream& is, Modint& x) noexcept { ll a; cin >> a; x = a; return is; }
inline constexpr Modint operator""_M(ull x) noexcept { return Modint(x); }
std::vector<Modint> fac(1, 1), inv(1, 1);
inline void reserve(ll a){
    if(fac.size() >= a) return;
    if(a < fac.size() * 2) a = fac.size() * 2;
    if(a >= Mod) a = Mod;
    while(fac.size() < a) fac.push_back(fac.back() * Modint(fac.size()));
    inv.resize(fac.size());
    inv.back() = fac.back().inv();
    for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
inline Modint fact(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
inline Modint perm(ll n, ll r){
    if(r < 0 || n < r) return 0;
    if(n >> 24){ Modint ans = 1; for(ll i = 0; i < r; i++) ans *= n--; return ans; }
    reserve(n + 1); return fac[n] * inv[n - r];
}
