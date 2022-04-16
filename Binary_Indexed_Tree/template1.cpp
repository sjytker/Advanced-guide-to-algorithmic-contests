// https://www.luogu.com.cn/problem/P3374
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, m;
int a[N], c[N];

int lowbit(int x) {
	return x & (-x);
}

void build() {
	for (int i = 1; i <= n; i ++) {
		c[i] += a[i];
		int j = i + lowbit(i);
		if (j <= n) c[j] += c[i];
	}
}

void add(int x, int t) {
	while (x <= n) {
		c[x] += t;
		x += lowbit(x);
	}
}

int sum(int x) {
	int res = 0;
	while (x >= 1) {
		res += c[x];
		x -= lowbit(x);
	}
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		// add(i, a[i]);
	}
	build();

	while (m --) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) {
			add(x, y);
		}
		if (op == 2) {
			cout << sum(y) - sum(x - 1) << endl;
		}
	}
	return 0;
}
