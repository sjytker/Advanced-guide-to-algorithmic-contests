#include<bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = 10010;

int a[N];
int f[M];


int main() {
    int n, m;
    int v;
    cin >> n >> m;
    f[0] = 1;
    // for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        cin >> v;
        for (int j = m; j >= v; j --) f[j] += f[j - v];
    }
    cout << f[m] << endl;
    return 0;
}