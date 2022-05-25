/*
*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int a[N], b[N];
PII p[N];
int n;

bool cmp(PII x, PII y) {
    return x.second < y.second;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    int res = 0;
    sort(p + 1,  p + 1 + n, cmp);
    int y = p[(n + 1) / 2].second;
    for (int i = 1; i <= n; i ++) {
        res += abs(p[i].second - y);
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i ++) p[i].first -= i - 1;
    sort(p + 1, p + 1 + n);
    int x = p[(n + 1) >> 1].first;
    for (int i = 1; i <= n; i ++) res += abs(p[i].first - x);
    cout << res << endl;
    return 0;
}