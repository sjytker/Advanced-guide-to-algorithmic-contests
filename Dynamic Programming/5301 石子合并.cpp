#include<bits/stdc++.h>
using namespace std;

const int N = 310;
int a[N];
int f[N][N];
int presum[N];

int main() {
    int n;
    cin >> n;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
        f[i][i] = 0;
    }

    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l <= n - len + 1; l ++) {
            int r = l + len  - 1;
            for (int k = l; k < r; k ++) 
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
            f[l][r] += presum[r] - presum[l - 1];
        }
    }
    cout << f[1][n] << endl;
    return 0;
} 