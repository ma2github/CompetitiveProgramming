/*
WaveletTree
reference:https://miti-7.hatenablog.com/entry/2018/04/28/152259
https://www.slideshare.net/pfi/ss-15916040
*/
#include  <bits/stdc++.h>
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
