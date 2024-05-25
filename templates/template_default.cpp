#define ll long long
 
#include <bits/stdc++.h>
using namespace std;
 
struct node{
	ll sum, pref, suf, seg;
};
 
int n, q, sz;
vector<node> tree;	
vector<ll> val;
 
const ll NO_OPER = LLONG_MIN;
 
node combine(node a, node b){
	return {
		a.sum + b.sum,
		max(a.pref, a.sum + b.pref), 
		max(b.suf, b.sum + a.suf),
		max({a.seg, b.seg, a.suf + b.pref})
	};
}
 
void push(int x, int lx, int rx){
	if(rx - lx == 1 || val[x] == NO_OPER) return;
	val[2*x + 1] = val[x];
	val[2*x + 2] = val[x];
	int mx = (lx + rx) >> 1;
	if(val[x] > 0){
		tree[2*x + 1] = {(mx - lx)*val[x], (mx - lx)*val[x], (mx - lx)*val[x], (mx - lx)*val[x]};
		tree[2*x + 2] = {(rx - mx)*val[x], (rx - mx)*val[x], (rx - mx)*val[x], (rx - mx)*val[x]};
	}else{
		tree[2*x + 1] = {(mx - lx)*val[x], 0LL, 0LL, 0LL};
		tree[2*x + 2] = {(rx - mx)*val[x], 0LL, 0LL, 0LL};
	}
	val[x] = NO_OPER;
	//tree[x] = combine(tree[2*x + 1], tree[2*x + 2]);
}
 
void update(int l, int r, ll v, int x, int lx, int rx){
	push(x, lx, rx);
	if(rx <= l || r <= lx) return;
	if(l <= lx && rx <= r){
		val[x] = v;
		if(v > 0) tree[x] = {(rx - lx)*v, (rx - lx)*v, (rx - lx)*v, (rx - lx)*v};
		else tree[x] = {(rx - lx)*v, 0LL, 0LL, 0LL};
		return;
	}
	int mx = (lx + rx) >> 1;
	update(l, r, v, 2*x + 1, lx, mx);
	update(l, r, v, 2*x + 2, mx, rx);
	tree[x] = combine(tree[2*x + 1], tree[2*x + 2]);
}
 
node get(int l, int r, int x, int lx, int rx){
	push(x, lx, rx);
	if(rx <= l || r <= lx) return {0LL, 0LL, 0LL, 0LL};
	if(l <= lx && rx <= r) return tree[x];
	int mx = (lx + rx) >> 1;
	return combine(get(l, r, 2*x + 1, lx, mx), get(l, r, 2*x + 2, mx, rx));
}
 
int main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);
 
	cin>>n>>q;
 
	sz = 1;
	while(sz < n) sz *= 2;
	tree.assign(2*sz - 1, {0LL, 0LL, 0LL, 0LL});
	val.assign(2*sz - 1, NO_OPER);
 
	while(q--){
		int l, r; ll v;
		cin>>l>>r>>v;
		update(l, r, v, 0, 0, sz);
		cout<<get(0, n, 0, 0, sz).seg<<"\n";
	}
}