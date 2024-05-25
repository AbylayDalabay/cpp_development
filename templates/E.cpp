#include <bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// find_by_order(k) - iterator on k's elements
// order_of_key(x) - number of elements, strictly less than x
 
// std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define vt vector
#define y1 ggwp
#define rt return
#define br break
#define cn continue
#define en '\n'
#define yes cout << "YES\n";
#define no cout << "NO\n"
#define yesno(x); cout << (x ? "YES\n" : "NO\n");
#define dbg(x) cout << (#x) << ": " << (x) << '\n';
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rev(x) reverse(x.begin(), x.end())
#define sz(x) (int)x.size()
#define left stupid_left
#define right stupid_right
 
template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
 
template<class T, class TT> void mineq(T& a, const TT& b){ if (b < a) a = b;}
template<class T, class TT> void maxeq(T& a, const TT& b){ if (b > a) a = b;}
 
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define file_io freopen(".in", "r", stdin); freopen(".out", "w", stdout)
 
typedef double ld;
typedef long long ll;
typedef vector<int> vi; 
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pii;
typedef vector<pair<int, int>> vii;
typedef vector<pair<ll, ll>> vll;

const int N = 2e5 + 500;
const int inf = 1e9;

int n;
string s;
vi ar, pref;
vii seg;

struct segtree_min{
    int sz = 1;
    vi t;
    segtree_min(){
        while(sz < n + 1) sz *= 2;
        t.assign(2 * sz - 1, inf);
    }
    void update(int i, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            t[x] = min(t[x], val); rt;
        }
        int mx = (lx + rx) >> 1;
        if(i < mx) update(i, val, 2 * x + 1, lx, mx);
        else update(i, val, 2 * x + 2, mx, rx);
        t[x] = min(t[2 * x + 1], t[2 * x + 2]);
    }
    int get(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) rt inf;
        if(l <= lx && rx <= r) rt t[x];
        int mx = (lx + rx) >> 1;
        rt min(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
    }
    void update(int i, int val){
        update(i, val, 0, 0, sz);
    }
    int get(int l, int r){
        rt get(l, r + 1, 0, 0, sz);
    }
};

struct segtree_max{
    int sz = 1;
    vi t;
    segtree_max(){
        while(sz < n + 1) sz *= 2;
        t.assign(2 * sz - 1, 0);
    }
    void update(int i, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            t[x] = max(t[x], val); rt;
        }
        int mx = (lx + rx) >> 1;
        if(i < mx) update(i, val, 2 * x + 1, lx, mx);
        else update(i, val, 2 * x + 2, mx, rx);
        t[x] = max(t[2 * x + 1], t[2 * x + 2]);
    }
    int get(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) rt 0;
        if(l <= lx && rx <= r) rt t[x];
        int mx = (lx + rx) >> 1;
        rt max(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
    }
    void update(int i, int val){
        update(i, val, 0, 0, sz);
    }
    int get(int l, int r){
        rt get(l, r + 1, 0, 0, sz);
    }
};

void solve(){
    cin >> n >> s; 
    ar.assign(n + 1, 0);
    for(int i = 1;i <= n;i++) ar[i] = s[i - 1] - '0';

    int m;
    cin >> m;
    for(int i = 0;i < m;i++){
        int x, d;
        cin >> x >> d;
        seg.pb({max(1, x - d), min(n, x + d)});
    }

    pref.assign(n + 1, 0);
    for(int i = 1;i <= n;i++) pref[i] = pref[i - 1] + ar[i];

    vt<vi> right_bounds(n + 1), left_bounds(n + 1);
    for(auto x : seg){
        right_bounds[x.s].pb(x.f);
        left_bounds[x.f].pb(x.s);
    }

    for(int i = 1;i <= n;i++){
        sort(all(right_bounds[i]));
        sort(all(left_bounds[i]));
    }

    ll ans = LLONG_MIN;

    // [x, ... (l, ... y] ... r)
    segtree_min A;
    for(int i = 1;i <= n;i++){
        for(auto left : right_bounds[i]){
            int res = A.get(1, left - 1);
            if(res != inf){
                maxeq(ans, i + pref[left - 1] - res + 1);
            }
        }
        for(auto left : right_bounds[i]){
            A.update(left, left + pref[i]);
        }
    }

    // [x ... (l, ..., r) ... y]
    segtree_max B;
    for(int i = n;i >= 1;i--){
        for(auto left : right_bounds[i]){
            int res = B.get(1, left - 1);
            if(res > 0){
                maxeq(ans, res - (pref[i] - pref[left - 1]));
            }
        }
        for(auto left : right_bounds[i]){
            B.update(left, i - left + 1);
        }
    }

    // kogda r sovpadayut
    for(int i = 1;i <= n;i++){
        if(sz(right_bounds[i]) >= 2){
            int first_pos = right_bounds[i][0];
            int last_pos = right_bounds[i].back();

            maxeq(ans, i - first_pos + 1 - (pref[i] - pref[last_pos - 1]));
        }
    }

    for(int i = 1;i <= n;i++){
        if(sz(left_bounds[i]) >= 2){
            int first_pos = left_bounds[i][0];
            int last_pos = left_bounds[i].back();

            maxeq(ans, last_pos - i + 1 - (pref[first_pos] - pref[i - 1]));
        }
    }

    cout << ans << en;
}   

int main(){
    fast_io;

    int tt = 1;
    // cin >> tt;
    for(int q = 1;q <= tt;q++){
        // cout << "Case #: " << q << en;
        solve();
    }
}   
 
/*
 
THE SOLUTION IS ALWAYS SIMPLE
THE CODE IS ALWAYS SHORT
 
1) попробуй сжать массив по одинаковым
2) преф суф??
3) сначала перебери тривиальные значения определенной переменной
4) check max, min value

*/
