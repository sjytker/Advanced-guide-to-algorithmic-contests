#include<iostream>

using namespace std;

const int N = 1010;
int n, s;
double f[N][N];

int main() {
	cin >> n >> s;
	for (int i = n; i >= 0; i --) {
		for (int j = s; j >= 0; j --) {
			if (i == n || j == s) continue;
			int t = n * s - i * j;
			double p1 = (double) i * j;
			double p2 = (double) i * (s - j);
			double p3 = (double) j * (n - i);
			double p4 = (double) (n - i) * (s - j);
			f[i][j] = (double)(p2 * f[i][j + 1] + p3 * f[i + 1][j] + p4 * f[i + 1][j + 1] + n * s) / t;
		}
	}
	printf("%.4f\n", f[0][0]);
	return 0;
}