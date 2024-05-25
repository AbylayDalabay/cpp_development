template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
}

template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}

string s;
cin >> s;

auto fuck = manacher(s);

bool is_pal(int l, int r){ // [0, n - 1]
    rt fuck[l + r] >= (r - l + 1) / 2;
}






class Manacher{
    vector<int> d1;
public:
    template<class T=string, class TT=char>
    Manacher(const T& x, TT d){
        T s(x.size()*2, d);
        for(size_t i = 0; i < x.size(); i++) s[2*i] = x[i];
        d1.assign(s.size(), 0);
        int l = 0, r = -1;
        for(int i = 0; i < (int)s.size(); i++){
            int& k = d1[i];
            k = (i > r ? 1 : min(d1[l+r-i], r-i+1));
            while(i+k < sz(s) && i-k >= 0 && s[i+k] == s[i-k]) k++;
            if (i+k-1 > r) l = i-k+1, r = i+k-1;
        }
    }
    int get(int pos, bool odd_length=true){
        if (odd_length) return (d1[pos*2]+1)/2;
        return d1[pos*2+1]/2;
    }
    bool is_pal(int l, int r){
        int len = r - l + 1;
        return get((l+r)>>1, len&1)*2 >= len;
    }
};