#include<bits/stdc++.h>

using namespace std;

int n, m;
const int N = 310;
int f[N][N];
vector<int> e[N];
int s[N];


int dfs(int u) {
	int p = 1;
	f[u][1] = s[u];

	for (int nx : e[u]) {
		int sz = dfs(nx);
		for (int i = min(p, m + 1); i; i --) {
			for (int j = sz; j >= 0; j --) {
				f[u][i + j] = max(f[u][i + j], f[nx][j] + f[u][i]);
			}
		}
		p += sz;
	}
	return p;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		int k;
		scanf("%d%d", &k, &s[i]);
		e[k].push_back(i);
	}
	dfs(0);
	printf("%d\n", f[0][m + 1]);
	return 0;
}