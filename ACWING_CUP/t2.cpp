
#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;	
	int len = 0;
	int t = n;
	while (t) {
		len ++;
		t /= 10;
	}
	int res = pow(2, len - 1) - 1;
	int a = pow(10, len);
	for(int i = len - 1; i >= 1; i --) {
		int b = a + pow(10, i);
		if (b <= n) {
			res += pow(2, i);
		}
	}
	cout << res << endl;
	return 0;
}