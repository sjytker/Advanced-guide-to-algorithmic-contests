#include<bits/stdc++.h>
using namespace std;

string a[5];
int n;
int res;


void dfs(int x, int y, int t) {
    if (y >= 5) {
        x ++, y = 0;
    }
    if (x >= 5) {
        for (int i = 0; i < 5; i ++) {
            if (a[4][i] != '1') return;
        }
        res = min(res, t);
        return;
    }
    if (x == 0) {
        dfs(x, y + 1, t);
        a[x][y] = '0' + ('1' - a[x][y]);
        a[x + 1][y] = '0' + ('1' - a[x + 1][y]);
        if (y > 0) a[x][y - 1] = '0' + ('1' - a[x][y - 1]);
        if (y < 4) a[x][y + 1] = '0' + ('1' - a[x][y + 1]);
        dfs(x, y + 1, t + 1);
        a[x][y] = '0' + ('1' - a[x][y]);
        a[x + 1][y] = '0' + ('1' - a[x + 1][y]);
        if (y > 0) a[x][y - 1] = '0' + ('1' - a[x][y - 1]);
        if (y < 4) a[x][y + 1] = '0' + ('1' - a[x][y + 1]);
    } else {
        if (a[x - 1][y] == '0') {
            a[x][y] = '0' + ('1' - a[x][y]);
            if (y > 0) a[x][y - 1] = '0' + ('1' - a[x][y - 1]);
            if (y < 4) a[x][y + 1] = '0' + ('1' - a[x][y + 1]);
            if (x < 4) a[x + 1][y] = '0' + ('1' - a[x + 1][y]);
            dfs(x, y + 1, t + 1);
            a[x][y] = '0' + ('1' - a[x][y]);
            if (y > 0) a[x][y - 1] = '0' + ('1' - a[x][y - 1]);
            if (y < 4) a[x][y + 1] = '0' + ('1' - a[x][y + 1]);
            if (x < 4) a[x + 1][y] = '0' + ('1' - a[x + 1][y]);
        } else {
            dfs(x, y + 1, t);
        }        
    }
}

int main() {
    cin >> n;
    while (n --) {
        for (int i = 0; i < 5; i ++) 
            cin >> a[i];
        
        res = INT_MAX;
        dfs(0, 0, 0);
        if (res > 6) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}