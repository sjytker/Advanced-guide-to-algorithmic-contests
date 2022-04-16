#include<bits/stdc++.h>

using namespace std;

const int N = 15;
long long f[N][1 << N][100];
int sit[1 << N], sta[1 << N];

int n, k;
int cnt;

void dfs(int x, int num, int cur) {
	if (cur >= n) {
		sit[++cnt] = x;
		sta[cnt] = num;
		return;
	}
	dfs(x, num, cur + 1);
	dfs(x + (1 << cur), num + 1, cur + 2);
}

bool check(int x, int y) {
	if (sit[x] & sit[y]) return false;
	if (sit[x] & (sit[y] << 1)) return false;
	if ((sit[x] << 1) & sit[y]) return false;
	return true;
}

int main() {
	cin >> n >> k;
	dfs(0, 0, 0);
	for (int i = 1; i <= cnt; i ++) f[1][i][sta[i]] = 1;
	for (int i = 2; i <= n; i ++) {
		for (int u = 1; u <= cnt; u ++) {
			for (int v = 1; v <= cnt; v ++) {
				if (!check(u, v)) continue;
				for (int l = sta[u]; l <= k; l ++) f[i][u][l] += f[i - 1][v][l - sta[u]];
			}
		}
	}
	long long res = 0;
	for (int i = 1; i <= cnt; i ++) res += f[n][i][k];
	cout << res << endl;
	return 0;
}