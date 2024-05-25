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

int n, m;

void solve(){
    cin >> n >> m;
    vt<vt<int>> ar(n + 5, vi(m + 5, 0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            char c;
            cin >> c;
            ar[i][j] = c - '0';
        }
    }

    vt<vt<int>> up_lef = vt<vt<int>>(n + 5, vi(m + 5, 0));
    vt<vt<int>> up_rig = vt<vt<int>>(n + 5, vi(m + 5, 0));
    vt<vt<int>> down_lef = vt<vt<int>>(n + 5, vi(m + 5, 0));
    vt<vt<int>> down_rig = vt<vt<int>>(n + 5, vi(m + 5, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(ar[i][j] == 1) up_lef[i][j] = 1 + up_lef[i - 1][j - 1];
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 1;j--){
            if(ar[i][j] == 1) up_rig[i][j] = 1 + up_rig[i - 1][j + 1];
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= m;j++){
            if(ar[i][j] == 1) down_lef[i][j] = 1 + down_lef[i + 1][j - 1];
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = m;j >= 1;j--){
            if(ar[i][j] == 1) down_rig[i][j] = 1 + down_rig[i + 1][j + 1];
        }
    }

    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(ar[i][j] == 1) maxeq(ans, up_lef[i][j] + up_rig[i][j] + down_lef[i][j] + down_rig[i][j] - 3);
        }
    }

    cout << ans << en;
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