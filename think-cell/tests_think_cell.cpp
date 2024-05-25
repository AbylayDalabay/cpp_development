#include <bits/stdc++.h>

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define ull unsigned long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define plll pair<pll, ll>
#define lpll pair<ll, pll>
#define FOR(i, start, stop) for(ll i = (start); i < (stop); i++)
#define fi(n)  FOR(i, 0, n)
#define fj(n)  FOR(j, 0, n)
#define fk(n)  FOR(k, 0, n)
#define fio(n) FOR(i, 1, n)
#define fjo(n) FOR(j, 1, n)
#define fko(n) FOR(k, 1, n)
#define fiv(n) for (ll i = n-1; i >= 0; i--)
#define fjv(n) for (ll j = n-1; j >= 0; j--)
#define fkv(n) for (ll k = n-1; k >= 0; k--)
#define f first
#define s second
#define pb push_back
#define rt return
#define cn continue;
#define br break;
#define sz(x) ((ll)x.size())
#define all(queries) begin(queries),end(queries)
#define rall(queries) (queries).rbegin(),(queries).rend()
#define YESNO(flag) cout<<(flag ? "YES" : "NO") <<'\n';
#define dbg(...) cerr << "\033[33m" << (#__VA_ARGS__) << ": "; dbg_vals(__VA_ARGS__); cerr << "\033[0m\n";
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class T> istream& operator>>(istream& in, vector<T>& x){for(T& i : x) in >> i; return in; }
template<class T, class TT> istream& operator>>(istream& in, pair<T, TT>& x){ in >> x.f >> x.s; return in; }
template<class T, class TT> ostream& operator<<(ostream& out, const pair<T, TT>& x){ out << "[" << x.f << ';' << x.s << "]"; return out; }
template <typename Iter, typename=decltype(declval<Iter>().begin()), typename=enable_if_t<!is_convertible_v<Iter, string>>> ostream& operator<<(ostream& out, const Iter& x){ for (const auto& i : x) out << i << ' '; return out;}

template<typename T> void dbg_vals(T x){ cerr<< "\033[31m" << x << "\033[0m"; }
template<typename T, typename... Args> void dbg_vals(T x, Args... args){ dbg_vals(x); cerr << " | "; dbg_vals(args...); }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<class T, class comp=less<T>> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// find_by_order(k) - iterator on k's elements
// order_of_key(x) - number of elements, strictly less than x

const ll MAXN = 2123456;
const ll MOD = 1000'000'007;
const ld EPS = 1e-10;
const ll INF = (ll)(1ll<<60) + (ll)((1ll<<31)-1);
const ld PI = atanl(1)*4;

ll rll(ll r=LLONG_MAX, ll l=0){ /*random long long*/ static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); return uniform_int_distribution<ll>(l, r)(rng); }
template<typename F> auto time_measure(F f){ auto start = chrono::steady_clock::now(); f(); auto end = chrono::steady_clock::now(); return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); }
template<class T, class TT> bool mineq(T& a, const TT& b){ if (b < a) {a = b; return true;} return false;}
template<class T, class TT> bool maxeq(T& a, const TT& b){ if (b > a) {a = b; return true;} return false;}



template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest(interval_map& mp);
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val) {
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

struct SIM{
    vector<char> vals;
    SIM(int x, char def): vals(x, def) {}
    void assign(int l, int r, char x){
        for(int i = l; i < r; i++) vals[i] = x;
    }
    char const& operator[](int key){ return vals[key]; }
};

struct Key{
    Key(int sad){ sad++; }
    friend bool operator<([[maybe_unused]]const Key& a,[[maybe_unused]] const Key& b){ return false; }
};
struct Val{
    Val(int zxc){ zxc++; }
    friend bool operator==([[maybe_unused]]const Val& a,[[maybe_unused]] const Val& b){ return false; }
};

ll n, m, k, q;
ll ar[MAXN];

void IntervalMapTest(interval_map<int, char>& mp){
    auto test = [&](int key, char ans){
        bool good = true;
        if (mp[key] != ans){
            good = false;
            dbg(key, mp[key], ans)
        }
        auto prev = mp.m_valBegin;
        for(auto [key, val] : mp.m_map){
            if (val == prev){
                good = false;
                dbg(prev, key, val)
                break;
            }
            prev = val;
        }
        if (!good){
            dbg("ERROR", mp.m_map)
            exit(1);
        }
    };
    if (1){
        test(0, ' ');
        dbg(mp.m_map, 0)
        mp.assign(1, 5, '1');
        mp.assign(3, 3, '2');
        mp.assign(6, 6, '3');
        mp.assign(555, 5, '4');
        dbg(mp.m_map, 1)
        test(0, ' ');
        test(1, '1');
        test(2, '1');
        test(4, '1');
        test(5, ' ');
        test(6, ' ');
        mp.assign(4, 5, '6');
        dbg(mp.m_map, 2)
        test(0, ' ');
        test(1, '1');
        test(2, '1');
        test(4, '6');
        test(5, ' ');
        test(6, ' ');
        mp.assign(0, 3, '7');
        dbg(mp.m_map, 3)
        test(-1, ' ');
        test(0, '7');
        test(1, '7');
        test(2, '7');
        test(3, '1');
        test(4, '6');
        test(5, ' ');
        test(6, ' ');
        mp.assign(2, 4, '9');
        dbg(mp.m_map, 4)
        test(-1, ' ');
        test(0, '7');
        test(1, '7');
        test(2, '9');
        test(3, '9');
        test(4, '6');
        test(5, ' ');
        test(6, ' ');
        mp.assign(2, 4, 'a');
        dbg(mp.m_map, 5)
        test(-1, ' ');
        test(0, '7');
        test(1, '7');
        test(2, 'a');
        test(3, 'a');
        test(4, '6');
        test(5, ' ');
        test(6, ' ');
        mp.assign(1, 7, 'b');
        dbg(mp.m_map, 6)
        test(-1, ' ');
        test(0, '7');
        test(1, 'b');
        test(2, 'b');
        test(3, 'b');
        test(4, 'b');
        test(5, 'b');
        test(6, 'b');
        test(7, ' ');
        mp.assign(10, 12, 'c');
        dbg(mp.m_map, 7)
        test(-1, ' ');
        test(0, '7');
        test(1, 'b');
        test(2, 'b');
        test(3, 'b');
        test(4, 'b');
        test(5, 'b');
        test(6, 'b');
        test(7, ' ');
        test(9, ' ');
        test(10, 'c');
        test(11, 'c');
        test(12, ' ');
        test(13, ' ');
        mp.assign(6, 11, 'd');
        dbg(mp.m_map, 8)
        test(-1, ' ');
        test(0, '7');
        test(1, 'b');
        test(2, 'b');
        test(3, 'b');
        test(4, 'b');
        test(5, 'b');
        test(6, 'd');
        test(7, 'd');
        test(9, 'd');
        test(10, 'd');
        test(11, 'c');
        test(12, ' ');
        test(13, ' ');
        mp.assign(-10, 456, '8');
        dbg(mp.m_map, 9)
        test(-11, ' ');
        test(-10, '8');
        test(450, '8');
        test(455, '8');
        test(456, ' ');
        mp.assign(456, 458, '8');
        dbg(mp.m_map, 10)
        test(-11, ' ');
        test(-10, '8');
        test(450, '8');
        test(455, '8');
        test(456, '8');
        test(457, '8');
        test(458, ' ');
        cerr << '\n';
        mp.assign(-12, 500, ' ');
        dbg(mp.m_map, 11)
        test(-13, ' ');
        test(-12, ' ');
        test(-11, ' ');
        test(-10, ' ');
        test(450, ' ');
        test(455, ' ');
        test(456, ' ');
        test(499, ' ');
        test(500, ' ');
        mp.assign(0, 1, 'a');
        mp.assign(1, 5, 'a');
        mp.assign(4, 8, 'a');
        mp.assign(8, 10, 'a');
        dbg(mp.m_map, 12)
        test(-1, ' ');
        test(0, 'a');
        test(1, 'a');
        test(2, 'a');
        test(3, 'a');
        test(4, 'a');
        test(5, 'a');
        test(6, 'a');
        test(7, 'a');
        test(9, 'a');
        test(10, ' ');
        test(11, ' ');
        mp.assign(4, 12, 'a');
        dbg(mp.m_map, 13)
        test(-1, ' ');
        test(0, 'a');
        test(1, 'a');
        test(2, 'a');
        test(3, 'a');
        test(4, 'a');
        test(5, 'a');
        test(6, 'a');
        test(7, 'a');
        test(9, 'a');
        test(10, 'a');
        test(11, 'a');
        test(12, ' ');
        mp.assign(5, 9, 'a');
        dbg(mp.m_map, 14)
        test(-1, ' ');
        test(0, 'a');
        test(1, 'a');
        test(2, 'a');
        test(3, 'a');
        test(4, 'a');
        test(5, 'a');
        test(6, 'a');
        test(7, 'a');
        test(9, 'a');
        test(10, 'a');
        test(11, 'a');
        test(12, ' ');
        mp.assign(0, 20, ' ');
        mp.assign(1, 10, 'a');
        dbg(mp.m_map, 15)
        mp.assign(5, 6, 'b');
        dbg(mp.m_map, 16)
        test(0, ' ');
        test(1, 'a');
        test(4, 'a');
        test(5, 'b');
        test(6, 'a');
        test(7, 'a');
        test(8, 'a');
        test(9, 'a');
    }

    cerr << '\n';
    dbg("SMALL TEST")
    auto test_small = [&](ll gen, int size, int cnt_q){
        mp = interval_map<int, char>('a');
        SIM sim(size, 'a');
        mt19937_64 _rng1(gen);
        uniform_int_distribution<int> distrib1(0, size-1);
        auto rndm = [&](){ return distrib1(_rng1); };
        mt19937_64 _rng2(gen);
        uniform_int_distribution<int> distrib2(97, 122);
        auto rndchar = [&](){ return (char)distrib2(_rng2); };
        while(cnt_q--){
            int l = rndm(), r = rndm();
            char t = rndchar();
            // dbg(mp.m_map)
            // dbg(l, r, t)
            mp.assign(l, r, t);
            sim.assign(l, r, t);
            // dbg(mp.m_map)
            // fi(size) cout << sim[i];
            // cerr << '\n';
            fi(size) test(i, sim[i]);
        }
    };
    test_small(0, 20, 1000);
    test_small(1, 100, 1000);
    // test_small(0, 20, 100000);
    // test_small(1, 100, 100000);
    // fi(10) test_small((int)rll(), 1000, 100000);

    cerr << '\n';
    dbg("BIG TEST")

    [[maybe_unused]] auto test_big = [&](){
        int cnt_q = 1e7;
        ll gen = rll();
        interval_map<ll, char>mp('a');
        mt19937_64 _rng1(gen);
        uniform_int_distribution<ll> distrib1(LLONG_MIN, LLONG_MAX);
        auto rndm = [&](){ return distrib1(_rng1); };
        mt19937_64 _rng2(gen);
        uniform_int_distribution<int> distrib2(97, 122);
        auto rndchar = [&](){ return (char)distrib2(_rng2); };
        
        auto func = [&](){
            vector<tuple<ll, ll, char>> qs(cnt_q);
            fi(cnt_q) qs[i] = {rndm(), rndm(), rndchar()};
            fi(cnt_q){
                auto [l, r, c] = qs[i];
                mp.assign(l, r, c);
            }
        };
        dbg(time_measure(func)/1e6)
    };
    // fi(3) cout << time_measure(test_big)/1e6 << '\n';
}

int main(){
    IOS;
    interval_map<int, char> mp(' ');
    IntervalMapTest(mp);
    dbg("OK")
    interval_map<Key, Val> asd(123);
    asd.assign(1, 2, 456);
    return 0;
}