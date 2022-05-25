/*
    Extremely hard to prove, refer to 《进阶指南》 for more details;
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1010;
int n, R;
struct Node {
    ll p, s, v;
    double avg;
} nodes[N];

int find() {
    double avg = 0;
    int res = -1;
    for (int i = 1; i <= n; i ++) {
        if (i != R && nodes[i].avg > avg) {
            avg = nodes[i].avg;
            res = i;
        }
    }
    return res;
}

int main() {
    while (cin >> n >> R, n + R) {
        ll res = 0;
        for (int i = 1; i <= n; i ++) {
            cin >> nodes[i].v;
            nodes[i].s = 1;
            nodes[i].avg = nodes[i].v; 
            res += nodes[i].v;
        }
        int a1, b1;
        for (int i = 0; i < n - 1; i ++) {
            cin >> a1 >> b1;
            nodes[b1].p = a1;
        }
        for (int i = 0; i < n - 1; i ++) {
            int x = find();
            int parent = nodes[x].p;
            res += nodes[x].v * nodes[parent].s;
            nodes[x].avg = -1;
            for (int j = 1; j <= n; j ++) {
                if (nodes[j].p == x) nodes[j].p = parent;
            }
            nodes[parent].s += nodes[x].s;
            nodes[parent].v += nodes[x].v;
            nodes[parent].avg = (double)nodes[parent].v / nodes[parent].s;
        }
        cout << res << endl;
    }
    return 0;
}