/*
*/
#include<bits/stdc++.h>
using namespace std;

const int N = pow(3, 8);
int n, T;
int a[N][N];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void dfs(int n, int x, int y) {
    if (n == 1) {
        a[x][y] = 1;
        return;
    }
    int len = power(3, n - 2);
    dfs(n - 1, x, y);
    dfs(n - 1, x, y + 2 * len);
    dfs(n - 1, x + len, y + len);
    dfs(n - 1, x + 2 * len, y);
    dfs(n - 1, x + 2 * len, y + 2 * len);
}

int main() {
    while (cin >> n, n != -1) {
        dfs(n, 1, 1);
        for (int i = 1; i <= power(3, n - 1); i ++) {
            for (int j = 1; j <= power(3, n - 1); j ++) {
                if (a[i][j]) cout << "X";
                else cout << " ";
            }
            cout << endl;
        }
        puts("-");
    }
    return 0;
}