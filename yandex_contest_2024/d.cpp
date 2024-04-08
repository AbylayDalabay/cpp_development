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

const int N = 3e5 + 500;

int n, suf_last[N];
string s;

struct state{
    ll cord;
    char dir;

    void step(){
        if(dir == 'R') cord++;
        if(dir == 'L') cord--;
    }
};

state pref[N];

void solve(){
    cin >> n >> s;
    s = "#" + s;

    pref[0] = {0, 'R'};
    for(int i = 1;i <= n;i++){
        pref[i] = pref[i - 1];
        if(s[i] == 'F') pref[i].step();
        else pref[i].dir = s[i];
    }

    for(int i = n;i >= 1;i--){
        suf_last[i] = suf_last[i + 1];
        if(s[i] != 'F') suf_last[i] = i;
    }

    struct changes{
        ll add_F;
        ll add;
    };

    vector<changes> suf(n + 5);
    suf[n + 1] = {0, 0};
    for(int i = n;i >= 1;i--){
        if(s[i] == 'L'){
            suf[i].add = suf[i + 1].add - suf[i + 1].add_F;
            suf[i].add_F = 0;
        }
        else if(s[i] == 'R'){
            suf[i].add = suf[i + 1].add + suf[i + 1].add_F;
            suf[i].add_F = 0;
        }
        else{
            suf[i].add_F = suf[i + 1].add_F + 1;
            suf[i].add = suf[i + 1].add;
        }
    }
    
    set<ll> ans;

    auto relax = [&](state A, changes B){
        ll ret = A.cord;
        if(A.dir == 'L') ret -= B.add_F;
        if(A.dir == 'R') ret += B.add_F;

        ret += B.add;

        ans.insert(ret);
    };

    for(int i = 1;i <= n;i++){
        for(char cur_dir : {'L', 'R', 'F'}){
            if(cur_dir != s[i]){
                if(cur_dir == 'L'){
                    state A = pref[i - 1];
                    A.dir = 'L';
                    relax(A, suf[i + 1]);
                }
                else if(cur_dir == 'R'){
                    state A = pref[i - 1];
                    A.dir = 'R';
                    relax(A, suf[i + 1]);
                }
                else{
                    state A = pref[i - 1];
                    A.step();
                    relax(A, suf[i + 1]);
                }
            }
        }
    }
    
    cout << ans.size() << en;
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