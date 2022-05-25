
/*
    模拟
*/
#include<bits/stdc++.h>
using namespace std;

deque<int> v[14];
int lives = 4;

int main() {
    for (int i = 1; i <= 13; i ++) {
        for (int j = 0; j < 4; j ++) {
            char t;
            cin >> t;
            int num;
            if (t >= '2' && t <= '9') num = t - '0';
            else if (t == 'A') num = 1;
            else if (t == '0') num = 10;
            else if (t == 'J') num = 11;
            else if (t == 'Q') num = 12;
            else if (t == 'K') num = 13;
            v[i].push_back(num);
        }
    }
    int res = 0;
    vector<int> cnt(14);
    while (lives) {
        int num = v[13][4 - lives];
        while (num != 13) {
            // cout << v[num].size() << ' ' << num << endl;
            v[num].push_front(num);
            int new_num = v[num].back();
            v[num].pop_back();    
            num = new_num;
            if (cnt[num] == 4) res ++;
        }
        lives --;
    }
    cout << res << endl;
    return 0;
}