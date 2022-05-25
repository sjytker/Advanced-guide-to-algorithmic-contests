/*
    两个奇数码可互相转化，等价于它们的逆序对奇偶性一致。证明见进阶指南；
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
long long res;
long long r1, r2;
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
    int x, n;
    while (cin >> n) {
        int k = n * n, i = 1;
        while (k --) {
            cin >> x;
            if (!x) continue;
            a[i] = x;
            i ++;
        }
        res = 0;
        merge(1, n * n - 1);
        r1 = res;
        i = 1, k = n * n;
        while (k --) {
            cin >> x;
            if (!x) continue;
            a[i] = x;
            i ++;
        }
        res = 0;
        merge(1, n * n - 1);
        r2 = res;
        if ((r1 % 2 == 0 && r2 % 2 == 0) || (r1 % 2 != 0 && r2 % 2 != 0))
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }
    return 0;
}