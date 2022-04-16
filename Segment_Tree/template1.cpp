
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;
ll a[N], d[N << 2], b[N << 2];
ll n, m;
ll x, y, k, op;

inline long long ls(long long x) {
	return 2 * x;
}

inline long long rs(long long x) {
	return 2 * x + 1;
}

void build(ll l, ll r, ll p) {
	if (l == r) {
		d[p] = a[l];
		return;
	}
	ll m = l + ((r - l) >> 1);
	build(l, m, ls(p));
	build(m + 1, r, rs(p));
	d[p] = d[ls(p)] + d[rs(p)];
}


void update(ll l, ll r, ll k, ll s, ll t, ll p) {
	if (l <= s && r >= t) {
		d[p] += (t - s + 1) * k;
		b[p] += k;
		return;
	}
	ll m = t + s >> 1;
	if (b[p] && s != t) {
		d[ls(p)] += b[p] * (m - s + 1);
		d[rs(p)] += b[p] * (t - m);
		b[ls(p)] += b[p];
		b[rs(p)] += b[p];
		b[p] = 0;
	}
	if (l <= m) update(l, r, k, s, m, ls(p));
	if (r > m) update(l, r, k, m + 1, t, rs(p));
	d[p] = d[ls(p)] + d[rs(p)];
}


long long query(ll l, ll r, ll s, ll t, ll p) {
	if (l <= s && r >= t) return d[p];
	ll m = t + s >> 1;
	long long res = 0;
	if (b[p]) {
		d[ls(p)] += b[p] * (m - s + 1);
		d[rs(p)] += b[p] * (t - m);
		b[ls(p)] += b[p];
		b[rs(p)] += b[p];
		b[p] = 0;
	}
	if (l <= m) res += query(l, r, s, m, ls(p));
	if (r > m) res += query(l, r, m + 1, t, rs(p));
	return res;
}


int main() {
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	build(1, n, 1);
	while (m --) {
		cin >> op;
		if (op == 1) {
			cin >> x >> y >> k;
			update(x, y, k, 1, n, 1);
		}
		if (op == 2) {
			cin >> x >> y;
			cout << query(x, y, 1, n, 1) << endl;
		}
	}
	return 0;
}