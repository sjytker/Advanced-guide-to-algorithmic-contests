#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

void dfs(int x) {
    if (x > n) {
        for (int i = 0; i < v.size(); i ++) cout << v[i] << ' '; cout << endl;
        return;
    }
    dfs(x + 1);
    v.push_back(x);
    dfs(x + 1);
    v.pop_back();
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}