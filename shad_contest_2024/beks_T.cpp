#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ar(n + 5, vector<int>(m + 5, 0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            char c;
            cin >> c;
            ar[i][j] = c - '0';
        }
    }

    vector<vector<int>> up = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> down = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> lef = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> rig = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));

    for(int j = 1;j <= m;j++){
        for(int i = 1;i <= n;i++){
            if(ar[i][j]) up[i][j] = up[i - 1][j] + 1;
        }
    }

    for(int j = 1;j <= m;j++){
        for(int i = n;i >= 1;i--){
            if(ar[i][j]) down[i][j] = down[i + 1][j] + 1;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(ar[i][j]) lef[i][j] = lef[i][j - 1] + 1;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 1;j--){
            if(ar[i][j]) rig[i][j] = rig[i][j + 1] + 1;
        }
    }

    long long ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(ar[i][j] == 0) continue;
            long long cur = up[i][j] + lef[i][j] + rig[i][j] + down[i][j];
            if(up[i][j] == 1) ans = max(ans, cur - 3ll);
            if(down[i][j] == 1) ans = max(ans, cur - 3ll);
            if(lef[i][j] == 1) ans = max(ans, cur - 3ll);
            if(rig[i][j] == 1) ans = max(ans, cur - 3ll);
        }
    } 

    cout << ans << endl;
}