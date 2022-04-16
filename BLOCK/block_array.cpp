// https://www.luogu.com.cn/problem/P2801

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, q;
int x, y, k, block, tot;
int a[N], d[N];
int st[N], ed[N];
int belong[N];
int dlt[N];

void fr(char &x)
{
    x=0;while(x!='M'&&x!='A') x=getchar();
}

template <typename Tp>
void read(Tp &x){
    x=0;char ch=1;int fh;
    while(ch!='-'&&(ch>'9'||ch<'0')){
        ch=getchar();
    }
    if(ch=='-'){
        fh=-1;ch=getchar();
    }else fh=1;
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';ch=getchar();
    }
    x*=fh;
}

void sort_block(int k) {
	for (int i = st[k]; i <= ed[k]; i ++) d[i] = a[i];
	sort(d + st[k], d + ed[k] + 1);
}

void build() {
	block = sqrt(n); tot = n / block;
	if (n % block) tot ++;
	for (int i = 1; i <= n; i ++) {
		belong[i] = (i - 1) / block + 1;
		d[i] = a[i];
	}
	for (int i = 1; i <= tot; i ++) {
		st[i] = (i - 1) * block + 1;
		ed[i] = i * block;
	}
	ed[tot] = n;
	for (int i = 1; i <= tot; i ++) {
		sort(d + st[i], d + ed[i] + 1);
	}
}

void modify(int l, int r, int c) {
	int x = belong[l], y = belong[r];
	if (x == y) {
		for (int i = l; i <= r; i ++) a[i] += c;
		sort_block(x);
		return;
	}
	for (int i = l; i <= ed[x]; i ++) a[i] += c;
	for (int i = st[y]; i <= r; i ++) a[i] += c;
	for (int i = x + 1; i < y; i ++) dlt[i] += c;
	sort_block(x);
	sort_block(y);
}

int answer(int l, int r, int c) {
	int x = belong[l], y = belong[r];
	int res = 0;
	if (x == y) {
		for (int i = l; i <= r; i ++) {
			if (a[i] + dlt[x] >= c) res ++;
		}
		return res;
	}
	for (int i = l; i <= ed[x]; i ++) if (a[i] + dlt[x] >= c) res ++;
	for (int i = st[y]; i <= r; i ++) if (a[i] + dlt[y] >= c) res ++;
	for (int i = x + 1; i < y; i ++) {
		res += ed[i] - (lower_bound(d + st[i], d + ed[i] + 1, c - dlt[i]) - d) + 1;
	}
	return res;
}

int main() {
	cin >> n >> q;
	// read(n); read(q);
	for (int i = 1; i <= n; i ++) {
		// read(a[i]);
		cin >> a[i];
	}
	build();
	for (int i = 1; i <= q; i ++) {
		char t;
		// read(t);
		// read(x); read(y); read(k);
		fr(t);
		cin >> x >> y >> k;
		if (t == 'M') {
			modify(x, y, k);
		} else if (t == 'A') {
			cout << answer(x, y, k) << endl;
		}
	}
	return 0;
}
