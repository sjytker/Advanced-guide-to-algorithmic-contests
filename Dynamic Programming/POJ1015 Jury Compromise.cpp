#include<bits/stdc++.h>

using namespace std;

const int N = 1100;
const int M = 30;

int n, m;
struct people{
    int p, d, sum, sub;
} a[210];

int f[M][2000], last[M][2000];

void input(int i) {
    cin >> a[i].p >> a[i].d;
    a[i].sum = a[i].p + a[i].d;
    a[i].sub = a[i].p - a[i].d;
}

bool select(int j, int t, int i) {
    while (last[j][t] != -1) {
        if (last[j][t] == -1) return true;
        t -= a[last[j][t]].sub;
        j --;
    }
    return false;
}


int main() {
    int t = 1;
    while (cin >> n >> m, n + m) {
        for (int i = 1; i <= n; i ++) {
            input(i);
            // cout << "n : " << i << endl;
        }
        memset(f, 0x8f, sizeof f);
        memset(last, 0xff, sizeof last);
        f[0][1000] = 0;

        for (int i = 1; i <= n; i ++)  {
            for (int j = m; j >= 1; j --) {
                if (j > i) continue;
                for (int k = 500; k <= 1500; k ++) {
                    if (f[j][k] < f[j - 1][k - a[i].sub] + a[i].sum) {
                        f[j][k] = f[j - 1][k - a[i].sub] + a[i].sum;
                        last[j][k] = i;
                    }
                }
            }
        }

        int mx = 0, res;
        int tot_p = 0, tot_d = 0;
        bool got = false;
        for (int i = 0; i <= 400; i ++) {
            if (f[m][1000 + i] > 0) {
                mx = f[m][1000 + i];
                res = 1000 + i;
                got = true;
            }
            if (f[m][1000 - i] > 0)  {
                if (f[m][1000 - i] > mx) {
                    mx = f[m][1000 - i];
                    res = 1000 - i;
                }
                got = true;
            }
            if (got) break;
        }

        int index = m;
        vector<int> v;
        while (last[index][res] != -1) {
            int i = last[index][res];
            v.push_back(i);
            index--, res -= a[i].sub;
            tot_p += a[i].p, tot_d += a[i].d;
        }
        sort(v.begin(), v.end());
        printf("Jury #%d\n", t++);
        printf("Best jury has value %d for prosecution and value %d for defence: \n", tot_p, tot_d);
        for (auto &i : v) {
            cout << i << ' ';
        } cout << endl << endl;;
    }
    return 0;
}

