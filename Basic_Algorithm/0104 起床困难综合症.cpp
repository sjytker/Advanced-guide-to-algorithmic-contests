#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 10;
int a[N];
string b[N];

int n, m;

int cal(int bit, int now) {
    for (int i = 1; i <= n; i ++) {
        int x = a[i] >> bit & 1;
        string op = b[i];
        if (op == "AND") now &= x;
        else if (op == "OR") now |= x;
        else now ^= x;
    }
    return now;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> b[i] >> a[i];
    }
    int val = 0, res = 0;
    for (int bit = 30; bit >= 0; bit --) {
        int res0 = cal(bit, 0);
        int res1 = cal(bit, 1);
        if (val + (1 << bit) <= m && res0 < res1) {
            val += 1 << bit;
            res += res1 << bit;
        } else {
            res += res0 << bit;
        }
    }
    cout << res << endl;
    return 0;
}