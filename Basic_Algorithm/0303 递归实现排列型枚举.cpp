#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int v[N], used[N];
int n;

void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; i ++) {
            cout << v[i] << ' ';
        } cout << endl;
        return;
    }
    for (int i = 1; i <= n; i ++) {
        if (used[i]) continue;
        used[i] = 1;
        v[x] = i;
        dfs(x + 1);
        used[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}