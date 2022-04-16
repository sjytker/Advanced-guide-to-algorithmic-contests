#include<bits/stdc++.h>

using namespace std;

const int N = 3010;

int f[N][N];
int a[N], b[N];



int main() {
    int res = -1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    for (int i = 1; i <= n; i ++) {
        int val = 0;
        for (int j = 1; j <= n; j ++) {
            if (a[i] == b[j]) f[i][j] = val + 1;
            else f[i][j] = f[i - 1][j];
            if (b[j] < a[i]) val = max(val, f[i - 1][j]);
            res = max(res, f[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}

// int main() {
//     int res = -1;
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i ++) cin >> a[i];
//     for (int i = 1; i <= n; i ++) cin >> b[i];
    
//     for (int i = 1; i <= n; i ++) {
//         for (int j = 1; j <= n; j ++) {
//             if (a[i] == b[j]) {
//                 for (int k = 1; k < j; k ++) {
//                     if (b[k] < a[i]) f[i][j] = max(f[i][j], f[i - 1][k] + 1);
//                 }
//             } else {
//                 f[i][j] = f[i - 1][j];
//             }
//         }
//     }
//     for (int i = 1; i <= n; i ++) res = max(res, f[n][i]);
//     cout << res << endl;
//     return 0;
// }

