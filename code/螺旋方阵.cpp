#include<bits/stdc++.h>
using namespace std;
int n,num[25][25],k,x,y;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	cin >> n;
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j <= n + 1; j++)
			num[i][j] = -1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			num[i][j] = 0;
	k = 0;
	x = 1;
	y = 1;
	for(int t = 1; t <= n * n; t++) {
		num[x][y] = t;
		if (num[x + dx[k]][y + dy[k]] != 0)
			k = (k + 1) % 4;
		x = x + dx[k];
		y = y + dy[k];
	}
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= n; j++)
			cout << setw(5) << num[i][j];
		cout << endl;
	}
	return 0;
}
