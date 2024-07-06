#include<bits/stdc++.h>
using namespace std;
int n,num[105][105];
int main() {
	cin >> n;
	for(int i = 1; i <= (n + 1) / 2; i++)
		for(int j = 1; j <= (n + 1) / 2; j++) {
			num[i][j] = min(i,j);
			num[n + 1 - i][j] = num[i][j];
			num[i][n + 1 - j] = num[i][j];
			num[n + 1 - i][n + 1 - j] = num[i][j];		
		}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			cout << setw(5) << num[i][j];
		cout << endl;
	}
	return 0;
}
