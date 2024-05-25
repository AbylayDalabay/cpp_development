#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> transform(pair<long long, long long> p){
    long long d = __gcd(p.first, p.second);
    p.first /= d;
    p.second /= d;
    return p;
}

int main(){
    int n;
    cin >> n;
    int ver = 0, hor = 0;
    map<pair<long long, long long>, int> cnt;

    for(int i = 0;i < n;i++){
        long long a, b, c;
        cin >> a >> b >> c;

        // ax + by + c = 0
        // y = (-a / b) x - c / b

        if(a == 0) hor++;
        else if(b == 0) ver++;
        else cnt[transform({-a, b})]++;
    }

    int q;
    cin >> q;
    while(q--){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            cout << ver << endl;
        }
        else if(b == 0){
            cout << hor << endl;
        }
        pair<long long, long long> beks = transform({b, a});

        cout << cnt[beks] << endl;
    }
}