#include <bits/stdc++.h>

#define ll long long
#define INF ((1ll<<62))
#define MAXN 1000101LL
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;


template<class T, T _inf, T _eps, T left_border, T right_border, bool is_max=false>
class LiChaoTree{
    struct Line{
        T k, b;
        Line *left, *righ;
        Line(T _k=0, T _b=_inf){
            k = _k, b = _b;
            left = righ = nullptr;
        }
        T val(T x){ return k*x + b; }
        Line* to_left(){
            if (!left) left = new Line();
            return left;
        }
        Line* to_righ(){
            if (!righ) righ = new Line();
            return righ;
        }
    };
    void swap_lines(Line& a, Line& b){
        swap(a.b, b.b);
        swap(a.k, b.k);
    }
    Line line[1];
    void add_line(Line nw, Line *v, T l, T r){
        T m = (l + r) / 2;
        bool lef = nw.val(l) < v->val(l);
        bool mid = nw.val(m) < v->val(m);
        if (mid) swap_lines(nw, *v);
        if (r - l <= _eps) return;
        if (lef != mid) add_line(nw, v->to_left(), l, m);
        else            add_line(nw, v->to_righ(), m, r);
    }
    T get(T x, Line *v, T l, T r){
        T m = (l + r) / 2;
        if (r - l <= _eps) return v->val(x);
        if (x < m) return min(v->val(x), get(x, v->to_left(), l, m));
                   return min(v->val(x), get(x, v->to_righ(), m, r));
    }
public:
    void add_line(T k, T b){
        add_line((is_max ? Line{-k, -b} : Line{k, b}), 
                 line, left_border, right_border);
    }
    T get(T x){
        return get((is_max ? -x : x), line, left_border, right_border);
    }
};

ll n, m, r, h, q, k;
ll a[MAXN], b[MAXN];
ll dp[MAXN];
const ll MAXA = 1e9+50;
LiChaoTree<ll, INF, 1, 0, MAXA> hull;
 
void solve(){
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];
    hull.add_line(b[0], 0);
    for (ll i = 1; i < n; i++){
        dp[i] =  hull.get(a[i]);
        hull.add_line(b[i], dp[i]);
    }
    cout << dp[n-1] << '\n';
} 

int main(){
    srand(time(NULL));
    IOS;
    ll _ = 1, I = 0;
    // cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}