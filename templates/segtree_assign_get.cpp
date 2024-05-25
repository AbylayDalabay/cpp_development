int n;
 
struct segtree_assign_get{
    int sz = 1;
    vl tree;
 
    const ll NO_OPER = -1;
 
    segtree_assign_get(){
        while(sz < n + 5) sz *= 2;
        tree.assign(2 * sz - 1, NO_OPER);
    }
    void push(int x, int lx, int rx){
        if(rx - lx == 1 || tree[x] == NO_OPER) return;
        tree[2*x + 1] = tree[x];
        tree[2*x + 2] = tree[x];
        tree[x] = NO_OPER;
    }
 
    void update(int l, int r, ll val, int x, int lx, int rx){
        push(x, lx, rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            tree[x] = val;
            return;
        }
        int mx = (lx + rx) >> 1;
        update(l, r, val, 2*x + 1, lx, mx);
        update(l, r, val, 2*x + 2, mx, rx);
    }
 
    ll get(int i, int x, int lx, int rx){
        push(x, lx, rx);
        if(rx - lx == 1) return tree[x];
        int mx = (lx + rx) >> 1;
        if(i < mx) return get(i, 2*x + 1, lx, mx);
        return get(i, 2*x + 2, mx, rx);
    }
    ll get(int i){
        rt get(i, 0, 0, sz);
    }
    void update(int l, int r, ll val){
        update(l, r + 1, val, 0, 0, sz);
    }
};
 
struct node{
    ll a, d, sum;
};
 
ll get_sum_arif_prog(int l, int r, ll a, ll d){ // [l, r)
    rt (a + a + d * (r - l - 1)) * (r - l) / 2;
}
 
struct segtree_arif_prog{
    int sz = 1;
    vt<node> t;
 
    segtree_arif_prog(){
        while(sz < n + 5) sz *= 2;
        t.assign(2 * sz - 1, {0ll, 0ll, 0ll});
    }
    void push(int x, int lx, int rx){
        if(rx - lx == 1) rt;
 
        int mx = (lx + rx) >> 1;
 
        t[2 * x + 1].a += t[x].a;
        t[2 * x + 1].d += t[x].d;
 
        t[2 * x + 2].a += (t[x].a + (mx - lx) * t[x].d);
        t[2 * x + 2].d += t[x].d;    
 
        t[2 * x + 1].sum += get_sum_arif_prog(lx, mx, t[x].a, t[x].d);
        t[2 * x + 2].sum += get_sum_arif_prog(mx, rx, (t[x].a + (mx - lx) * t[x].d), t[x].d);
 
        assert(t[x].sum == t[2 * x + 1].sum + t[2 * x + 2].sum);
 
        t[x].a = 0ll;
        t[x].d = 0ll;
    }
    void update(int l, int r, ll add_a, ll add_d, int x, int lx, int rx){
        push(x, lx, rx);
        if(rx <= l || r <= lx) rt;
        if(l <= lx && rx <= r){
            t[x].a += (add_a + add_d * (lx - l));
            t[x].d += add_d;
 
            t[x].sum += get_sum_arif_prog(lx, rx, add_a + add_d * (lx - l), add_d);
            rt;
        }
        int mx = (lx + rx) >> 1;
        update(l, r, add_a, add_d, 2 * x + 1, lx, mx);
        update(l, r, add_a, add_d, 2 * x + 2, mx, rx);
        t[x].sum = t[2 * x + 1].sum + t[2 * x + 2].sum;
    }
    ll get(int l, int r, int x, int lx, int rx){
        push(x, lx, rx);
        if(rx <= l || r <= lx) rt 0ll;
        if(l <= lx && rx <= r){
            rt t[x].sum;
            // + get_sum_arif_prog(lx, rx, t[x].a, t[x].d);
        }
        int mx = (lx + rx) >> 1;
        rt get(l, r, 2 * x + 1, lx, mx) + get(l, r, 2 * x + 2, mx, rx);
    }
    void update(int l, int r, ll add_a, ll add_d){
        update(l, r + 1, add_a, add_d, 0, 0, sz);
    }
    ll get(int l, int r){
        rt get(l, r + 1, 0, 0, sz);
    }
};