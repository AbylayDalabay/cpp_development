const int N = 2e5 + 500;
const int K = 20;

int n, m, par[N], up[N][K + 1];
int tin[N], tout[N], T = 0;

vi g[N], gr[N];

void calc(int v, int p){
    par[v] = p;
    for(auto to : g[v]){
        if(to != p){
            gr[v].pb(to);
            calc(to, v);
        }
    }
}

void dfs(int v){
    tin[v] = T++;

    up[v][0] = par[v];
    for(int i = 1;i <= K;i++){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }

    for(auto to : gr[v]) dfs(to);

    tout[v] = T++;
}

bool is_ancestor(int a, int b){
    rt (tin[a] <= tin[b] && tout[b] <= tout[a]);
}
 
int lca(int a, int b){
    if(is_ancestor(a, b)) rt a;
    if(is_ancestor(b, a)) rt b;
 
    for(int i = K;i >= 0;i--){
        if(up[a][i] != 0 && !is_ancestor(up[a][i], b)){
            a = up[a][i];
        }
    }
    rt up[a][0];
}

void solve(){
    cin >> n >> m;
    for(int i = 0;i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    calc(1, 0);
} 