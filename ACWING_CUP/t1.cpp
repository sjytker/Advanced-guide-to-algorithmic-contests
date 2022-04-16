
#include<bits/stdc++.h>

using namespace std;

int p1, p2, p3, p4, a, b;

int main() {
	cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
	int p = min({p1, p2, p3, p4});
	int res = p - a;
	if (p < a) cout << 0 << endl;
	else if (p > b) cout << b - a + 1 << endl;
	else {
		cout << res << endl;
	}
	return 0;
}