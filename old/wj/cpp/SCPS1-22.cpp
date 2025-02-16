#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int n, k, a[12], b[12], ans[12], fa[12];
int findfa(int u) { return u == fa[u] ? u : fa[u] = findfa(fa[u]); }
int functionUnknown(int a[], int n) {
	if (n <= 1) return 0;
	int i = n - 1, j, k;
	while (true) {
		j = i; --i;
		if (a[i] < a[j]) {
			for (k = n; a[i] >= a[--k];);
			swap(a[i], a[k]);
			reverse(a + j, a + n);
			return 1;
		}
		if (!i) {
			reverse(a, a + n);
			return 0;
		}
	}
	return -1;
}
int F(int x) {
	int ans = 0;
	for (int i = k - 1; ~i; --i)
		ans = (1ll * ans * x % mod + a[i]) % mod;
	return ans;
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) scanf("%d", a + i);
	for (int m = 1; m <= n; ++m) {
		for (int i = 0; i < m; ++i) b[i] = i;
		do {
			for (int i = 0; i < m; ++i) fa[i] = i;
			int res = m;
			for (int i = 0, u, v; i < m; ++i) {
				u = findfa(i); v = findfa(b[i]);
				if (u == v) continue; --res; fa[u] = v;
			}
			int flag = 0;
			for (int i = 0; i < m; ++i)
				if (b[i] == i) flag = 1;
			if (flag) continue;
			ans[m] = (ans[m] + F(res)) % mod;
		} while(functionUnknown(b, m));
		printf("%d%c",ans[m]," \n"[m == n]);
	}
	return 0;
}

