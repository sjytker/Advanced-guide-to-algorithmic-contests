#include<bits/stdc++.h>
using namespace std;

const int M = 100010;
const int N = 110;

bool f[M];
int a[N], c[N];
int used[M];

int main() {
    int n, m;
    while ((cin >> n >> m) && (n || m)) {
        memset(f, 0, sizeof f);
        memset(a, 0, sizeof a);
        memset(c, 0, sizeof c);
        f[0] = true;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int i = 1; i <= n; i ++) cin >> c[i];

        for (int i = 1; i <= n; i ++) {
            memset(used, 0, sizeof used);
            for (int j = a[i]; j <= m; j ++) {
                if (!f[j] && f[j - a[i]] && used[j - a[i]] < c[i]) {
                    f[j] = true;
                    used[j] = used[j - a[i]] + 1;
                }
            }
        }
        int res = 0;
        for (int j = 1; j <= m; j ++) res += f[j];
        cout << res << endl;
    }
    return 0;
}