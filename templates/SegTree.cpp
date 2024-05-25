struct SegTree{
    int n, sz;
    vi t;

    SegTree(int n){
        sz = 1;
        while(sz < n) sz *= 2;
        t.assign(2 * sz - 1, 0);
    }

    void upd(int i, int x, int lx, int rx){
        if(rx - lx == 1){
            t[x] = 1;
            rt;
        }
        int mx = (lx + rx) / 2;
        if(i < mx) upd(i, 2 * x + 1, lx, mx);
        else upd(i, 2 * x + 2, mx, rx);
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }

    int get(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) rt 0;
        if(l <= lx && rx <= r) rt t[x];
        int mx = (lx + rx) / 2;
        rt get(l, r, 2 * x + 1, lx, mx) + get(l, r, 2 * x + 2, mx, rx);
    }

    void upd(int i){
        upd(i, 0, 0, sz);
    }

    int get(int l, int r){
        rt get(l, r + 1, 0, 0, sz);
    }
};