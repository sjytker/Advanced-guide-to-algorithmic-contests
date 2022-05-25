/*
    HARD 倍增，看了几小时；
    对于每一段，倍增右侧端点 r，check(l, r, r + len)，若合法 len <<= 1，否则 len >>= 1，直到 len == 0；
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500010;
ll a[N], b[N];
int K, n, m, t;
ll res;

ll sq(int x) {
    return x * x;
}

bool check(int l, int r) {
    int sum = 0;
    int k = 0;
    for (int i = l; i < r; i ++) b[k++] = a[i];
    sort(b, b + k);
    // for (int i = 0; i <= k; i ++) cout << b[i] << ' '; cout << endl;
    for (int i = 0; i < k && i < m; i ++, k --) sum += sq(b[i] - b[k - 1]);
    // cout << sum << ' ' << t << endl;
    return sum <= t;
}

ll solve() {
    int l = 0, r = 0;
    ll res = 0;
    while (r < n) {
        int len = 1;
        while (len) {
            if (r + len <= n && check(l, r, r + len)) {
                r += len;
                len <<= 1;
            } else {
                len >>= 1;
            }
        }
        l = r;
        res ++;
    }
    return res;
}

int main() {
    cin >> K;
    while (K--) {
        cin >> n >> m >> t;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        cout << solve() << endl;
    }
    return 0;
}