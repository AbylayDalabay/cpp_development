// #pragma GCC target( "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <queue>
#include <numeric>
#include <bitset>
#include <stdio.h>
#include <time.h>
#include <assert.h> 
// #include <bits/stdc++.h>

#define int long long
#define pb push_back
#define f first
#define s second
#define ndl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ryoiki_tenkai ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define muryokusho srand(time(0));

const double pi = 3.14159265359;
const int mod = 998244353;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const long long inf = 1ll<<62;
const int P = 31;
const int maxn = 200200;

using namespace std;
int p[L][maxn];
int tin[maxn];
int tout[maxn];
int lev[maxn];
long long w[maxn];
int timer = 0;
void dfs(int v, int pa) {
    lev[v] = lev[pa] + 1;
    // w[v]=w[pa]+ww;
    tin[v] = timer;
    timer++;
    p[0][v] = pa;
    for(int i = 1; i < L; i++) {
        p[i][v]= p[i-1][p[i-1][v]];
    }
    for(auto to: g[v]) {
        if(to.F != pa) {
            w[to.F] = w[v] + to.S;
            dfs(to.F, v);
        }
    }
    tout[v] = timer-1;
}
int parent(int u, int v) {
    if(tin[u] <= tin[v] && tout[u] >= tout[v]) {
        return 1;
    }
    return 0;
}
int lca(int u, int v) {
    if(parent(u, v)) {
        return u;
    } 
    if(parent(v, u)) {
        return v;
    }
    for(int i = L-1; i >= 0; i--) {
        if(p[i][v] != 0 && !parent(p[i][v], u)) {
            v = p[i][v];
        }
    }
    return p[0][v];
}
int t[20][100100];
int a[100100];
int lg[100100];
void precalc() {
    for(int i = 1; i <= n; i++) {
        t[0][i] = a[i];
    }
    for(int k = 1; (1<<k) <= n; k++) {
        for(int i = 1; i+(1<<k)-1<= n; i++) {
            t[k][i] = min(t[k-1][i], t[k-1][i+(1<<(k-1))]);
        }
    }
    lg[1] = 0;
    for(int i = 2; i <= n; i++) {
        lg[i] = lg[i/2] + 1;
    }
}
int get(int l, int r) {
    int k = lg[r-l+1];
    return min(t[k][l], t[k][r-(1<<k) + 1]);
}
long long bm(long long a, long long b) {
   if(b==0) return 0ll;
   if(b&1) return (bm(a, b-1) + a)%c;
   long long res=bm(a, b>>1ll);
   return (res+res)%c;
}
long long bp(long long a, long long b) {
   if(b==0) return 1ll;
   if(b&1) return bm(bp(a, b-1), a);
   long long res=bp(a, b>>1ll);
   return bm(res, res)%c;
}
void infinite() {
    

}
signed main() {    
    ryoiki_tenkai
    muryokusho
    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

    #endif
    int tt=1;
    // cin>>tt;
    for(int i=1;i<=tt;i++) {
        // cout<<"Case "<<i<<": ";
        infinite();
    }
    return 0;
}
void build(int v = 1, int tl = 1, int tr = n) {
    if(tl == tr) {
        t[v] = a[tl];
    } else {
        int mid = (tl + tr)>>1;
        build(v*2, tl, mid);
        build(v*2+1, mid+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void push(int v, int tl, int tr){
    if(tl == tr) return;
    int mid = (tl + tr)>>1;
    if(p[v] == 1) {
        t[v*2] += add[v] * (mid-tl+1);
        t[v*2+1] += add[v] * (tr-mid);
        add[v*2] += add[v];
        add[v*2+1] += add[v];
        if(p[v*2] == 0) p[v*2] = 1;
        if(p[v*2+1] == 0) p[v*2+1] = 1;
        p[v] = 0;
        add[v] = 0;
    }  
    else if(p[v] == 2){
        t[v*2] = add[v] * (mid-tl+1);
        t[v*2+1] = add[v] * (tr-mid);
        add[v*2] = add[v];
        add[v*2+1] = add[v];
        p[v*2] = 2;
        p[v*2+1] = 2; 
        p[v] = 0;
        add[v] = 0;
    }
}
long long get(int l, int r, int v = 1, int tl = 1, int tr = n) {
    push(v, tl, tr);
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return t[v];
    int mid = (tl + tr)>>1;
    return get(l, r, v*2, tl, mid) + get(l, r, v*2+1, mid+1, tr);
}
void upd(int l, int r, long long x, int v = 1, int tl = 1, int tr = n) {
    push(v, tl, tr);
    if(tl > r || tr < l) return;
    if(tl >= l && tr <= r) {
        t[v] = x * (tr - tl + 1);
        add[v] = x;
        p[v] = 2;
    } else {
        int mid = (tl + tr)>>1;
        upd(l, r, x, v*2, tl, mid);
        upd(l, r, x, v*2+1, mid+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void upd_add(int l, int r, long long x, int v = 1, int tl = 1, int tr = n) {
    push(v, tl, tr);
    if(tl > r || tr < l) return;
    if(tl >= l && tr <= r) {
        t[v] += x * (tr - tl + 1);
        add[v] += x;  
        if(p[v] == 0) p[v] = 1;
    } else {
        int mid = (tl + tr)>>1;
        upd_add(l, r, x, v*2, tl, mid);
        upd_add(l, r, x, v*2+1, mid+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}








void push(int v, int tl, int tr){
    if(tl == tr) return;
    int mid = (tl + tr)>>1;
    if(p[v]) {
        t[v * 2] = (mid - tl + 1) - t[v * 2];
        t[v * 2 + 1] = (tr - mid) - t[v * 2 + 1];
        p[v * 2] ^= 1;
        p[v * 2 + 1] ^= 1;
        p[v] = 0;
    }
}
long long get(int l, int r, int v = 1, int tl = 1, int tr = n) {
    push(v, tl, tr);
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return t[v];
    int mid = (tl + tr)>>1;
    return get(l, r, v*2, tl, mid) + get(l, r, v*2+1, mid+1, tr);
}
void upd(int l, int r, int v = 1, int tl = 1, int tr = n) {
    push(v, tl, tr);
    if(tl > r || tr < l) return;
    if(tl >= l && tr <= r) {
        t[v] = (tr - tl + 1) - t[v];
        p[v] = 1;
    } else {
        int mid = (tl + tr)>>1;
        upd(l, r, v*2, tl, mid);
        upd(l, r, v*2+1, mid+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}