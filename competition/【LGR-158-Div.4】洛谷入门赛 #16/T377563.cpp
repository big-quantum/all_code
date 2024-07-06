#include <bits/stdc++.h>

const int MAXN = 5000;

int n, ans;

bool f[MAXN + 5];

std::vector<int> k[MAXN + 5];

void dfs(int x) {
	if (f[x] == true) {
		return;
	}
	f[x] = true;
	ans++;
	for (auto i: k[x]) {
		dfs(i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int s;
		scanf("%d", &s);
		for (int j = 1; j <= s; j++) {
			int t;
			scanf("%d", &t);
			k[i].push_back(t);
		}
	}
	dfs(1);
	printf("%d", ans);
	return 0;
}
