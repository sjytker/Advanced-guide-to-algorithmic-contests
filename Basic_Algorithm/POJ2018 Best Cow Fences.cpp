#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
double a[N], b[N], sum[N];
int n, f;

bool valid(double x) {
    for (int i = 1; i <= n; i ++) b[i] = a[i] - x;
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + b[i];
    double res = -1e10;
    double val = 1e10;
    for (int i = f; i <= n; i ++) {
        val = min(val, sum[i - f]);
        res = max(res, sum[i] - val);
    }
    return res >= 0;
}

int main() {
    cin >> n >> f;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        // b[i] = b[i - 1] + a[i - 1];
    }
    b[0] = INT_MAX;
    double eps = 1e-9;
    double l = 1e-6, r = 1e6;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (valid(mid)) l = mid;
        else r = mid;
    }
    // cout << l << ' ' << r << endl;
    // cout << 1000 * l << ' ' << 1000 * r << endl;
    l = 1.0006;
    cout << floor(1000 * l) << endl;
    cout << int(1000 * l) << endl;
    return 0;
}