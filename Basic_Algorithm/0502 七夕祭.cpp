/*
    行和列分开看待，当沿着列交换时只改变每行数量，当沿着行交换时只改变列数量；
    对于每行/每列，可视作 “均分纸牌” 问题；
    设 a[i] = c[i] - T / M, 其前缀和为 s[i] = \sigma a[j], 那么总交换次数为 \sigma |s[i]|；
    而环状的均摊纸牌，可以证明，总存在一个点，其不同时往左右两侧分摊纸牌，那么我们就可以在这个点把环断开。
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
long long col[N], row[N];
long long a[N], b[N];
long long sum1[N], sum2[N];
long long n, m, t;


int main() {
    long long x, y;
    cin >> n >> m >> t;
    for (int i = 1; i <= t; i ++) {
        cin >> x >> y;
        row[x] ++, col[y] ++;
    }
    long long u = t / n, v = t / m;
    for (int i = 1; i <= n; i ++) a[i] = row[i] - u;
    for (int i = 1; i <= m; i ++) b[i] = col[i] - v;
    for (int i = 1; i <= n; i ++) sum1[i] = sum1[i - 1] + a[i];
    for (int i = 1; i <= m; i ++) sum2[i] = sum2[i - 1] + b[i];

    if (t % n && t % m) {
        cout << "impossible" << endl;
        return 0;
    } 

    sort(sum1 + 1, sum1 + n + 1);
    sort(sum2 + 1, sum2 + m + 1);

    long long tot_row = 0, tot_col = 0;
    x = sum1[n / 2 + 1];
    for (int i = 1; i <= n; i ++) tot_row += abs(sum1[i] - x);
    x = sum2[m / 2 + 1];
    for (int i = 1; i <= m; i ++) tot_col += abs(sum2[i] - x);

    if (t % n == 0 && t % m == 0) {
        cout << "both " << tot_row + tot_col;
    } else if (t % n == 0) {
        cout << "row " << tot_row;
    } else {
        cout << "column " << tot_col;
    }
    return 0;
}
