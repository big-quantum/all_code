#include<bits/stdc++.h>
using namespace std;
int num[105][105],n,x,y;
int main(){
	cin >> n;
	n = 2 * n - 1;
	x = 1;
	y = (n + 1) / 2;
	for(int t = 1;t <= n * n;t++){
		num[x][y] = t;
		int nx = x - 1;
		int ny = y + 1;
		if (nx == 0)
			nx = n;
		if (ny == n + 1)
			ny = 1;
		if (num[nx][ny] != 0){
			nx = x + 1;
			ny = y;
		}
		x = nx;
		y = ny;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < n;j++)
			cout << num[i][j] << " ";
		cout << num[i][n] << endl;
	}
}
