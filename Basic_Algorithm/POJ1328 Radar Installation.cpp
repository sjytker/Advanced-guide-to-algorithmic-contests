/*
    greedy.
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, d;
int eps = 1e-4;
struct node{
    double x, y;
}a[N];

bool cmp(node x, node y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

int solve() {
    sort(a + 1, a + 1 + n, cmp);
    int res = 0;
    double last = -1e5;
    for (int i = 1;i <= n; i ++) {
        if (a[i].x > last) {
            last = a[i].y;
            res ++;
        } else if (a[i].y < last) {
            last = a[i].y;
        }
    }
    return res;
}

int main() {
    int t = 1;
    while (cin >> n >> d, n + d) {
        int x, y;
        bool success = true;
        for (int i = 1; i <= n; i ++) {
            cin >> x >> y;
            if (y > d) {
                success = false;
            } else {
                double len = sqrt(d * d - y * y);
                a[i] = {x - len, x + len};
            }
        }
        if (!success) {
            cout << "Case " << t << ": " << -1 << endl;
        } else {
            cout << "Case " << t << ": " << solve() << endl;
        }
        t ++;
    }
    return 0;
}