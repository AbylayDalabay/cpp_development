ll fact[N], invFact[N];

ll bin_pow (ll a, ll b) {
    if (!b) {
        return 1;
    }
    else if (b % 2) {
        return a * bin_pow(a, b - 1) % mod;
    }
    else {
        ll lol = bin_pow(a, b / 2);
        return lol * lol % mod;
    }
}

int binpow(long long a, int n, int mod) {
    long long r = 1;
    while (n) {
        if (n & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return r;
}

ll binpow (ll a, ll n) {
    ll res = 1LL;
    while (n > 0)
        if (n % 2 == 1) {
            res *= a;
            res %= MOD;
            --n;
        }
        else {
            a *= a;
            a %= MOD;
            n /= 2;
        }
    return res;
}

const ll MOD = 998244353;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b){
    rt binpow(a, b, MOD);
}

void calc(){
    fact[0] = invFact[0] = 1;
    for(int i = 1;i < N;i++){
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = binpow(fact[i], MOD - 2);
    }
}

ll C(int n, int k){
    return (((fact[n] * invFact[n - k]) % MOD) * invFact[k]) % MOD;
}
