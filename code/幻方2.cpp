#include<bits/stdc++.h>
using namespace std;

int num[40][40],n,x,y;

int main() {
	cin >> n;
	n = 2 * n - 1;
	x = 1;
	y = (1 + n) / 2;
	for(int t = 1; t <= n * n; t++) {
		num[x][y] = t;
		if (t % n == 0)
			x++;
		else{
			x--;			
			y++;
			if (x == 0)
				x = n;
			if (y == n + 1)
				y = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < n; j++)
			cout << num[i][j] << " ";
		cout << num[i][n] << endl;
	}
	return 0;
}
