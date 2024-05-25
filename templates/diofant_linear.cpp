/////////////////////////////////////////////////////////////////
// EMAXX
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

struct solution{
    bool ok;
    int a, b, g;
};

solution solve_diofant_linear(int a, int b, int c){
    // a * x + b * y = c
    // {x, y}
    int x, y, g;
    bool ok = find_any_solution(a, b, c, x, y, g);
    return {ok, x, y, g};
}

/////////////////////////////////////////////////////////////////





// LONG LONG

/////////////////////////////////////////////////////////////////
// EMAXX
ll gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

struct solution{
    bool ok;
    ll x, y;
};

solution solve_diofant_linear(ll a, ll b, ll c){
    // a * x + b * y = c
    // {x, y}
    ll x, y, g;
    bool ok = find_any_solution(a, b, c, x, y, g);
    return {ok, x, y};
}

/////////////////////////////////////////////////////////////////