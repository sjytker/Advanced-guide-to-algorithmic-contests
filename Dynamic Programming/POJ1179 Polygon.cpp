#include<bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int fx[N][N], fn[N][N];
int op[N];

int main() {
    cin >> n;
    char c;
    memset(fx, 0x8f, sizeof fx);
    memset(fn, 0x3f, sizeof fn);
    for (int i = 1; i <= n; i ++) {
        cin >> c;
        op[i + n - 1] = op[i - 1] = (c == 't');
        cin >> fn[i][i];
        fx[i + n][i + n] = fx[i][i] = fn[i + n][i + n] = fn[i][i];
    }
    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= 2 * n; l ++) {
            int r = l + len - 1;
            for (int k = l; k < r; k ++) {
                if (op[k] == 1) {
                    fx[l][r] = max(fx[l][r], fx[l][k] + fx[k + 1][r]);
                    fn[l][r] = min(fn[l][r], fn[l][k] + fn[k + 1][r]);
                } else {
                    fx[l][r] = max(fx[l][r], fx[l][k] * fx[k + 1][r]);
                    fx[l][r] = max(fx[l][r], fx[l][k] * fn[k + 1][r]);
                    fx[l][r] = max(fx[l][r], fn[l][k] * fn[k + 1][r]);
                    fx[l][r] = max(fx[l][r], fn[l][k] * fx[k + 1][r]);

                    fn[l][r] = min(fn[l][r], fx[l][k] * fx[k + 1][r]);
                    fn[l][r] = min(fn[l][r], fx[l][k] * fn[k + 1][r]);
                    fn[l][r] = min(fn[l][r], fn[l][k] * fn[k + 1][r]);
                    fn[l][r] = min(fn[l][r], fn[l][k] * fx[k + 1][r]);
                }
            }
        }
    }

    int mx = -0x3f3f3f3f;
    vector<int> a;
    for (int i = 1; i <= n; i ++) {
        if (fx[i][i + n - 1] > mx) {
            a.clear();
            mx = fx[i][i + n - 1];
        } 
        if (fx[i][i + n - 1] == mx) a.push_back(i - 1);
    }
    cout << mx << endl;
    for (auto &i : a) cout << i << ' ';
    return 0;
}