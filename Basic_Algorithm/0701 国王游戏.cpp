#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;
struct node {
    ll a, b;
    friend bool operator < (const node x, const node y) {
        return x.a * x.b < y.a * y.b;
    }
}num[N];

int n;
ll a, b;

vector<int> mul(vector<int> &v, int x) {
    int t = 0;
    vector<int> res;
    for (int i = 0; i < v.size(); i ++) {
        t += v[i] * x;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}

vector<int> div(vector<int> &v, int y) {
    vector<int> res;
    bool first = true;
    int t = 0;
    for (int i = v.size() - 1; i >= 0; i --) {
        t = t * 10 + v[i];
        int x = t / y;
        if (x || !first) {
            res.push_back(x);
            first = false;
        }
        t %= y;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> max_vec(vector<int> &v1, vector<int> v2) {
    int n1 = v1.size(), n2 = v2.size();
    if (n1 < n2) return v2;
    if (n1 > n2) return v1;
    for (int i = n1 - 1; i >= 0; i --) {
        if (v1[i] < v2[i]) return v2;
        if (v1[i] > v2[i]) return v1;
    }
    return v1;
}

int main() {
    cin >> n;
    cin >> a >> b;
    num[0] = {a, b};
    for (int i = 1; i <= n; i ++) {
        cin >> a >> b;
        num[i] = {a, b};
    }
    sort(num + 1, num + 1 + n);
    vector<int> res(1);
    vector<int> v(1, 1);
    for (int i = 0; i <= n; i ++) {
        if (i) res = max_vec(res, div(v, num[i].b));
        v = mul(v, num[i].a);
    }
    for (int i = res.size() - 1; i >= 0; i --) cout << res[i]; cout << endl;
    return 0;
}