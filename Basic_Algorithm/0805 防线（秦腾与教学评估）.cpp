/*
    二分
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int T;
int n, s, e, d;
int s[N];
int INF = 0x3f3f3f3f;
struct Node {
    int s, e, d;
} a[N];

int sum(int r) {
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i].s < r) {
            res += (min(r, a[i].e) - a[i].s) / a[i].d + 1;
        }
    }
    return res;
}

int main() {
    cin >> T;
    int l = INF, r = -INF;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].s >> a[i].e >> a[i].d;
            l = min(l, a[i].s);
            r = max(r, a[i].e);
        }
        if (sum(r) % 2 == 0) cout << "There's no weakness." << endl;
        else {

        }
    }
    return 0;
}
