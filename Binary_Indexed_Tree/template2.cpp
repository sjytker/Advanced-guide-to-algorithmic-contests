// https://www.luogu.com.cn/problem/P3374
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, m;
int a[N], c[N], b[N];

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
		b[i] = a[i] - a[i - 1];
		add(i, b[i]);
	}

	while (m --) {
		int op, x, y, k;
		cin >> op; 
		if (op == 1) {
			cin >> x >> y >> k;
			add(x, k);
			add(y + 1, -k);
		}
		if (op == 2) {
			cin >> x;
			cout << sum(x) << endl;
		}
	}
	return 0;
}
