int n, k, sz[N], S[N];
bool used[N];
double ans[N];
vector<int> g[N];
 
void dfs(int v, int pr = 0) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == pr)
            continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}
 
int findCentroid(int v) {
    for (int to : g[v]) {
        if (used[to])
            continue;
        if (sz[to] * 2 > sz[v]) {
            sz[v] -= sz[to];
            sz[to] += sz[v];
            return findCentroid(to);
        }
    }
    return v;
}