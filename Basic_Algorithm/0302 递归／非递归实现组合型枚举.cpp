#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n, m;

void dfs(int x) {
    if (v.size() > m || v.size() + (n - x + 1) < m) return;
    if (v.size() == m) {
        for (int i = 0; i < v.size(); i ++) cout << v[i] << ' '; cout << endl;
        return;
    }
    v.push_back(x);
    dfs(x + 1);
    v.pop_back();
    dfs(x + 1);
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}