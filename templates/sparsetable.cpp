struct SparseTable {
  vector<vector<int>> table;
  SparseTable() {}
  SparseTable(const vector<int>& a) {
    int n = a.size(), h = bit_width(a.size());
    table.resize(h);
    table[0] = a;
    for (int i = 1; i < h; i += 1) {
      table[i].resize(n - (1 << i) + 1);
      for (int j = 0; j + (1 << i) <= n; j += 1) {
        table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  int query(int l, int r) {
    int h = bit_width(unsigned(r - l)) - 1;
    return min(table[h][l], table[h][r - (1 << h)]);
  }
};

const int N = 1e5 + 5;

int logs[N];

struct sparse_table{
    vector<int> ar;
    vector<vector<int>> sparse;

    sparse_table(const vector<int> &ar){
        int n = ar.size();
        int maxpow = ceil(log2(n + 1));
        sparse.assign(maxpow, vector<int>(n, 0));
        sparse[0] = ar;
        for (int k = 0; k + 1 < maxpow; k++) {
            for (int ind = 0; ind + (1 << k) < n; ind++) {
                sparse[k + 1][ind] = __gcd(sparse[k][ind], sparse[k][ind + (1 << k)]);
            }
        }
    }
    
    int get(int l, int r) { // [l, r)
        r++;
        int power = logs[r - l];
        return __gcd(sparse[power][l], sparse[power][r - (1 << power)]);
    }   
};

logs[1] = 0;
    for (int i = 2; i < N; i++) {
        logs[i] = logs[i >> 1] + 1;
    }