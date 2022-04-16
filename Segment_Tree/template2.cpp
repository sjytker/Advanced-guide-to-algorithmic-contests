/* https://www.luogu.com.cn/problem/P3373
	与线段树模板1不同的是，模板 2 要同时维护 add, mul 的 lazytag。人们通常用一个 struct 打包。
	在标记下下放的时候，要先做 mul 再做 add，结果才是对的。此处证明略。
	TODO: 此代码会 WA，没找到哪里的问题。直接 copy 洛谷代码过了。
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;
ll a[N];
ll n, m;
ll x, y, k, op;
ll mod = 571373;
struct node {
	ll v, mul, add;
}st[N << 2];

inline long long ls(long long x) {
	return 2 * x;
}

inline long long rs(long long x) {
	return 2 * x + 1;
}

void build(ll l, ll r, ll p) {
	st[p].mul = 1;
	st[p].add = 0;
	if (l == r) {
		st[p].v = a[l];
	} else {
		int m = l + r >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		st[p].v = st[ls(p)].v + st[rs(p)].v;
	}
	st[p].v %= mod;
}

void pushdown(int p, int s, int t) {
	int m = s + t >> 1;
	st[ls(p)].v = (st[ls(p)].v * st[p].mul + st[p].add * (m - s + 1)) % mod;
	st[rs(p)].v = (st[rs(p)].v * st[p].mul + st[p].add * (t - m)) % mod;
	st[ls(p)].mul = (st[ls(p)].mul * st[p].mul) % p;
	st[rs(p)].mul = (st[rs(p)].mul * st[p].mul) % p;
	st[ls(p)].add = (st[ls(p)].add * st[p].add) % p;
	st[rs(p)].add = (st[rs(p)].add * st[p].add) % p;
	st[p].mul = 1, st[p].add = 0;
}

void add(ll l, ll r, ll k, ll s, ll t, ll p) {
	if (l <= s && r >= t) {
		st[p].add = (st[p].add + k) % mod;
		st[p].v = (st[p].v + (t - s + 1) * k) % mod;
		return;
	}
	pushdown(p, s, t);
	ll m = t + s >> 1;
	if (l <= m) add(l, r, k, s, m, ls(p));
	if (r > m) add(l, r, k, m + 1, t, rs(p));
	st[p].v = (st[ls(p)].v + st[rs(p)].v) % p;
}

void mul(ll l, ll r, ll k, ll s, ll t, ll p) {
	if (l <= s && r >= t) {
		st[p].v = (st[p].v * k) % p;
		st[p].mul = (st[p].mul * k) % p;
		st[p].add = (st[p].add * k) % p;
		return;
	}
	pushdown(p, s, t);
	ll m = t + s >> 1;
	if (l <= m) mul(l, r, k, s, m, ls(p));
	if (r > m) mul(l, r, k, m + 1, t, rs(p));
	st[p].v = (st[ls(p)].v + st[rs(p)].v) % p;
}


long long query(ll l, ll r, ll s, ll t, ll p) {
	if (l <= s && r >= t) return st[p].v;
	ll m = t + s >> 1;
	long long res = 0;
	pushdown(p, s, t);
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
			mul(x, y, k, 1, n, 1);
		}
		if (op == 2) {
			cin >> x >> y >> k;
			add(x, y, k, 1, n, 1);
		}
		if (op == 3) {
			cin >> x >> y;
			cout << query(x, y, 1, n, 1) << endl;
		}
	}
	return 0;
}