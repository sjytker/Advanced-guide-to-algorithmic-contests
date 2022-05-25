/*
    等价于归并统计逆序对问题
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int n;
long long res;
int a[N], b[N];

void merge(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], res += mid - i + 1;
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int i = l; i <= r; i ++) a[i] = b[i];
}

int main() {
    while (cin >> n, n) {
        for (int i = 1; i <= n; i ++) cin >> a[i];
        res = 0;
        merge(1, n);
        cout << res << endl;
    }
    return 0;
}