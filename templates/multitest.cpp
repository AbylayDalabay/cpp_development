#include <bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// find_by_order
// order_of_key
 
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
 
int binpow (int a, int n) {
    int res = 1;
    while (n)
        if (n & 1) {
            res *= a;
            --n;
        }
        else {
            a *= a;
            n >>= 1;
        }
    return res;
}

void solve(){

}
 
int main(){
    // fast_io;
    
    int tt = 1;
    // cin >> tt;
    for(int q = 1;q <= tt;q++){
        //cout << "Case #: " << q << en;
        solve();
    }
}  

ll binpow (ll a, ll n) {
    ll res = 1LL;
    while (n > 0)
        if (n % 2 == 1) {
            res *= a;
            res %= MOD;
            --n;
        }
        else {
            a *= a;
            a %= MOD;
            n /= 2;
        }
    return res;
}

const int N = 2e5 + 500;

ll fact[N], invFact[N];

ll C(int n, int k){
    return (((fact[n] * invFact[n - k]) % MOD) * invFact[k]) % MOD;
}

fact[0] = fact[1] = 1LL;
    for(int i = 2;i < N;i++) fact[i] = (fact[i - 1] * i) % MOD;
    // for(int i = 0;i < N;i++) invFact[i] = binpow(fact[i], MOD - 1);


#include <bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// find_by_order
// order_of_key
 
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
const ll MOD = 998244353;
const ll inf = LLONG_MAX;

int n;
ll a[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    int pos = n + 1;
    for(int i = 1;i <= n;i++){
        if(i % 2 == 1 && a[i] >= 0){ pos = i; br; }
        if(i % 2 == 0 && a[i] <= 0){ pos = i; br; }
    }

    ll ans = 0;
    for(int i = pos;i <= n;i++){
        if(a[i] > 0) ans += a[i];
    }

    ll mx = 0, cur_sum = 0;
    for(int i = pos - 1;i >= 1;i--){
        if(i % 2 == 0){
            maxeq(mx, cur_sum);
            cur_sum += a[i];
        }
        if(i % 2 == 1){
            maxeq(mx, cur_sum + a[i]);
        }
    }

    cout << ans + mx << en;
}   
 
int main(){
    fast_io;

    int tt = 1;
    cin >> tt;
    for(int q = 1;q <= tt;q++){
        //cout << "Case #: " << q << en;
        solve();
    }
}
