/*
    对 maxSPF 排序，然后贪心使用能用的最小 SPF[i];
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2510;
int cnt[N];
int c, l;

struct node{
    int l, r;
}a[N];

bool cmp(node x, node y) {
    return x.r < y.r;
}

int main() {
    cin >> c >> l;
    int mi, mx;
    int u, v;
    for (int i = 1; i <= c; i ++) {
        cin >> mi >> mx;
        a[i] = {mi, mx};    
    }
    for (int i = 1; i <= l; i ++) {
        cin >> u >> v;
        cnt[u] += v;
    }
    sort(a + 1, a + c + 1, cmp);
    int res = 0;
    for (int i = 1; i <= c; i ++) {
        for (int j = a[i].l; j <= a[i].r; j ++) {
            if (cnt[j]) {
                cnt[j] --;
                res ++;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}