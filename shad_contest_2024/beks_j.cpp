#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> ar(n);
    for(auto &x : ar) cin >> x;
    sort(ar.begin(), ar.end());
    int ans_l = -1, ans_r = -1;
    double ans_lambda = 1e18;

    for(int i = 0;i + k - 1 < n;i++){
        double cur_lambda = (ar[i + k - 1] - ar[i] + 0.0) / (double)ar[i];
        if(cur_lambda < ans_lambda){
            ans_lambda = cur_lambda;
            ans_l = i;
            ans_r = i + k - 1;
        }
    }
    cout << fixed << setprecision(9) << ans_lambda << endl;
    for(int i = ans_l;i <= ans_r;i++) cout << ar[i] << " ";
}