#include<bits/stdc++.h>

using namespace std;

const int N = 110;
int res, n, m;

struct Node {
	int a, b;
	double f;	
} node[N];

bool operator<(Node p, Node q) { return p.f > q.f; }

int f(int t , int v) {
	int tot = 0;
	for (int i = 1; t + i <= n; i ++) {
		if (v >= node[t + i].a) { 
			tot += node[t + i].b;	
			v -= node[t + i].a;
		} else {
			return (int)(tot + v * node[i + t].f);
		}
	}
	return tot;
}

void dfs(int t, int p, int v) {
	res = max(res, v);
	if (t > n) return;
	if (f(t, p) + v > res) dfs(t + 1, p, v);
	if (p >= node[t].a) dfs(t + 1, p - node[t].a, v + node[t].b);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> node[i].a >> node[i].b;
		node[i].f = 1.0 * node[i].b / node[i].a;
	}
	sort(node + 1, node + n  + 1);
	dfs(1, m, 0);
	cout << res << endl;
	return 0;
}