#include <bits/stdc++.h>

const int MAXN = 11, dx[] = {0, 1}, dy[] = {1, 0};

int n, m;
long long ans;
bool a[MAXN + 5][MAXN + 5];

void dfs(int x, int y) {
	if (x > n + 1 || y > m + 1) {
		return;
	}
	if (x == n && y == m && a[m][n] == true) {
		ans++;
		return;
	}
	if (y > m) {
		x++;
		y = 1;
	}
	if (a[x][y] == true) {
		dfs(x, y + 1);
		return;
	}
	for (int d = 0; d < 2; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (a[nx][ny] == false) {
			a[x][y] = a[nx][ny] = true;
			dfs(x, y + 1);
			a[x][y] = a[nx][ny] = false;
		}
	}
}

int main() {
	for (int i = 1; i <= 11; i++) {
		for (int j = 1; j <= 11; j++) {
			n = i; m = j;
			if (n * m % 2 == 1) {
				std::cout << "f[" << i << "]["<< j << "] = " << 0 << ";" << std::endl;
				continue;
			}
			if (n == 0 && m == 0) {
				break;
			}
			ans = 0;
			memset(a, true, sizeof(a));
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					a[i][j] = false;
				}
			}
			dfs(1, 1);
			std::cout << "f[" << i << "]["<< j << "] = " << ans << ";" << std::endl;
		}	
	}
	getchar();
	return 0;
}
