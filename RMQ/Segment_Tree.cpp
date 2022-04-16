#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

const int N = 1e5 + 10;
ll, n, m, a[N], tag[N << 1], res[N << 1];

inline ll ls(ll x) {return x << 1;}
inline ll rs(ll x) {return x << 1 | 1}

void scan() {
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) scanf("%lld", &a[i]);
}


int main() {
	ll x, l, r, k;
	scan()
	build(1, 1, n);
	while (m --) {
		scanf("%lld", &x);
		switch(x) {
			case 1: {
				scanf("%lld%lld%lld", &l, &r, &k);
				update(l, r, 1, )
			}
		}
	}
}