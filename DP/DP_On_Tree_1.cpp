#include<bits/stdc++.h>

using namespace std;

const int N = 6*1e3 + 10;
int h[N], e[N], ne[N], vis[N], f[N][2], idx;
int is_sub[N];
int n;

void add(int k, int l) {
	e[idx] = l, ne[idx] = h[k], h[k] = idx++;
}

void dfs(int u) {
	vis[u] = 1;
	for (int i = h[u]; i != -1; i = ne[i]) {
		auto t = e[i];
		if (vis[t]) continue;
		dfs(t);
		f[u][0] += max(f[t][0], f[t][1]);
		f[u][1] += f[t][0];
	}
}

int main() {
	scanf("%d", &n);
	memset(h, 0xff, sizeof h);
	for (int i = 1; i <= n; i ++) scanf("%d", &f[i][1]);
	for (int i = 1; i < n; i ++) {
		int l, k;
		scanf("%d%d", &l, &k);
		is_sub[l] = 1;
		add(k, l);
	}
	for (int i = 1; i <= n; i ++) {
		if (!is_sub[i]) {
			dfs(i);
			printf("%d", max(f[i][0], f[i][1]));
		}
	}
	return 0;
}