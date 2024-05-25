#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
template<class T, class comp=less<T>> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// find_by_order(k) - iterator on k's element
// order_of_key(x) - number of elements, strictly less than x
 
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
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
typedef pair<ll, ll> pll;
typedef vector<pair<int, int>> vii;
typedef vector<pair<ll, ll>> vll;  

/*
 
THE SOLUTION IS ALWAYS SIMPLE
THE CODE IS ALWAYS SHORT
 
1) попробуй сжать массив по одинаковым
2) преф суф??
3) сначала перебери тривиальные значения определенной переменной
4) check max, min value

*/

pll get(pll p){
    ll d = __gcd(p.f, p.s);
    p.f /= d;
    p.s /= d;
    rt p;
}

void solve(){
    int n;
    cin >> n;
    bool is_vertical = 0, is_horizontal = 0;
    set<pll> st;

    for(int i = 0;i < n;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        is_vertical |= (b == 0);
        is_horizontal |= (a == 0);

        if(b != 0){
            pll slope = {-a, b};
            slope = get(slope);
            st.insert(slope);
        }
    }

    int q;
    cin >> q;
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        bool ans = 0;

        if(a == 0){
            yesno(is_vertical); cn;
        }
        if(b == 0){
            yesno(is_horizontal); cn; 
        }
        pll slope = {-a, b};
        slope = get(slope);

        yesno(st.count(slope));
    }
}         

int main(){
    fast_io;

    int test_cases = 1;
    // cin >> test_cases;
    for(int _ = 1;_ <= test_cases;_++){
        //cout << "Case #: " << _ << en;
        solve();
    }
}   