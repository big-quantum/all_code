#include<bits/stdc++.h>
using namespace std;

int num[6][6],m,n;

int main() {
	for(int i = 1;i <= 5;i++)
		for(int j = 1;j <= 5;j++)
			cin >> num[i][j];
	cin >> m >> n;
	for(int j = 1;j <= 5;j++)
		swap(num[m][j],num[n][j]);
	for(int i = 1;i <= 5;i++){
		for(int j = 1;j < 5;j++)
			cout << num[i][j] << " ";
		cout << num[i][5] << endl;
	}
	return 0;
}
