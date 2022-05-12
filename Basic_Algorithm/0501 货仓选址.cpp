/*
    最优选址就是数组的中位数 X。
    证明：
        假设左侧有 P 家商店，右侧有 Q 家商店；
        若 P < Q，那么往右移动一个单位，则距离总和减少 Q - P;
        反之，距离总和减少 P - Q；
        当 P = Q 时达到均衡点。
*/
#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x = a[n / 2];
    int res = 0;
    for (int i = 1; i <= n; i ++) res += abs(a[i] - x);
    cout << res << endl;
    return 0;
}