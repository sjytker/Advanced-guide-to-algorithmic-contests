/*
可以结合回文字符串的视角来看，每找到一个新的回文字符，就等价于给树加上了一个新的 node，此时：
1. 子树完全不变，该 node 只有一个出度，其状态计数为子树的 copy: f[l][r] = f[l + 1][r - 1]
2. 重新划分左右子树，既遍历 l < k < r，当 s[l] == s[k] 时，说明改字符串划分下，左右子树是合法的。
    i. 子树一：f[l + 1][k - 1]
    ii. 子树二：f[k][r]
3. 需要注意的是，上述子树二必须是带根的，因为本题的树是多叉的，在子树二的遍历序列中，根节点 node 可能经过了多次
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 310;
string s;
ll n, f[N][N];
int M = 1e9;

int main() {
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i ++) f[i][i] = 1;
    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            if (s[l] != s[r]) continue;
            f[l][r] = f[l + 1][r - 1];
            for (int k = l + 1; k < r; k ++) {
                if (s[l] != s[k]) continue;
                f[l][r] += f[l + 1][k - 1] * f[k][r];
                f[l][r] %= M;
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}