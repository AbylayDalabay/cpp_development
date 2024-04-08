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

void solve(){
    string input_string;
    getline(cin, input_string);

    int max_length = 0;
    int count = 0;
    string substring = "";
    vector<string> substrings;
    for (int i = 0; i < input_string.size(); i++) {
        if (input_string[i] != ' ' && input_string[i] != ',') {
            substring += input_string[i];
        } else {
            while (i < input_string.size() && input_string[i] == ' ') {
                i++;
            }

            if (input_string[i] == ',') {
                substring += input_string[i];
                substrings.push_back(substring);
                substring = "";
            } else {
                if (!substring.empty()) {
                    substrings.push_back(substring);
                }

                if (input_string[i] != ' ') {
                    substring = input_string[i];
                } 
            }
        }
    }

    if (!substring.empty()) {
        substrings.push_back(substring);
    }   

    for (string sub : substrings) {
        int length = sub.size();
        if (sub[sub.size() - 1] == ',') {
            length--;
        }

        max_length = max(max_length, length);
    }

    max_length *= 3;
    int tab = 0;

    string output_string;
    for (int i = 0; i < substrings.size(); i++) {
        tab += substrings[i].size();
        if (tab <= max_length) {
            output_string += substrings[i];
            output_string += " ";
            tab++;
        } else {
            output_string.pop_back();
            output_string += "\n";
            output_string += substrings[i];
            output_string += " ";
            tab = substrings[i].size();
            tab++;
        }
    }

    output_string.pop_back();
    cout << output_string;
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