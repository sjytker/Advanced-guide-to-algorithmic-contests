#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ll a, b, p;
    cin >> a >> b >> p;
    ll res = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
    }
    cout << res << endl;
    return 0;
}