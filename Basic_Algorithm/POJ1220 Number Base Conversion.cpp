/*
    进制转换，用竖式模拟；
    数组每位存一个 s 进制的数，然后循环除以 d 进制，直到余数为 0；
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int T;
int s, d;
char x[N];
int nu[N], idx;
int res[N];
unordered_map<char, int> c2i;
char i2c[100];

void solve() {
    int n = strlen(x + 1);
    for (int i = 1; i <= n; i ++)
        nu[i] = c2i[x[i]];
    idx = 0;
    int cur = 1;
    while (cur <= n) {
        for (int i = cur; i <= n; i ++) {
            int b = nu[i] % d;
            nu[i] /= d;
            if (i != n) nu[i + 1] += b * s;
            else nu[i + 1] = b;
        }
        res[idx++] = nu[n + 1];
        while (cur <= n && nu[cur] == 0) cur ++;
    }
}

int main() {
    cin >> T;
    int t = 0;
    for (char i = '0'; i <= '9'; i ++) c2i[i] = t, i2c[t] = i, t ++;
    for (char i = 'A'; i <= 'Z'; i ++) c2i[i] = t, i2c[t] = i, t ++;
    for (char i = 'a'; i <= 'z'; i ++) c2i[i] = t, i2c[t] = i, t ++;
    while (T--) {
        scanf("%d%d", &s, &d);
        scanf("%s", x + 1);
        printf("%d %s\n%d ", s, x + 1, d);
        solve();
        for (int i = idx - 1; i >= 0; i --) putchar(i2c[res[i]]);
        puts("\n");
    }
    return 0;
}
