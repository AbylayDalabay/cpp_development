#include <bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
//template<class T, class comp=less<T>> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
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

const int K = 26;

struct node {
    int val = -1, index = -1;
    
    int subtree_val = -1, subtree_index = -1;
    
    int next[K];
    bool output = false;
    
    node(){
        fill(begin(next), end(next), -1);
    }
};

struct Trie{
    vector<node> trie;
    vector<int> prefix_path;

    Trie(){
        trie.emplace_back();
        prefix_path.push_back(0);
    }

    void add_string(string const& s, int add_val, int index) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].output = true;
        trie[v].val = add_val;
        trie[v].index = index;
    }

    void dfs(int v, int c){
        trie[v].subtree_val = trie[v].val;
        trie[v].subtree_index = trie[v].index;   
        for(int i = 0;i < K;i++){
            if(trie[v].next[i] != -1){
                int to_index = trie[v].next[i];
                dfs(to_index, i);
            
                if(trie[to_index].subtree_val > trie[v].subtree_val){
                    trie[v].subtree_val = trie[to_index].subtree_val;
                    trie[v].subtree_index = trie[to_index].subtree_index;
                }
            }
        }
    }  

    int add(char c){
        int last = prefix_path.back();
        if(last == -1){
            prefix_path.push_back(-1);
            return -1;
        }
        
        int child_index = trie[last].next[c - 'a'];
        
        prefix_path.push_back(child_index);
        if(child_index == -1) return -1;
        
        return trie[child_index].subtree_index;
    }    

    int del(){
        prefix_path.pop_back();  
        
        int last = prefix_path.back();
        
        if(last == -1) return -1;
        
        return trie[last].subtree_index;
    }  
};

void solve(){
    int n, q;
    cin >> n >> q;

    Trie T = Trie();
    vector<string> w(n);
    vector<int> p(n);
    for(int i = 0;i < n;i++){
        cin >> w[i] >> p[i];
        T.add_string(w[i], p[i], i);
    }

    T.dfs(0, 0);

    while(q--){
        char op;
        cin >> op;

        if(op == '+'){
            char c;
            cin >> c;

            int ans = T.add(c);

            cout << (ans == -1 ? -1 : ans + 1) << endl;
        }else{
            int ans = T.del();

            cout << (ans == -1 ? -1 : ans + 1) << endl;
        }
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

