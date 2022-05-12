#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N  = 4010;
ll f[N];
int M = 2147483648;

int main() {
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            f[j] += f[j - i];
            f[j] %= M;
        }
    }
    cout << f[n] - 1 << endl;
    return 0;
}