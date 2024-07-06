#include<bits/stdc++.h>
using namespace std;
int n,num[105][105];
int main() {
	cin >> n;
	for(int k = 1; k <= n; k++) {
		for(int i = k; i <= n; i++)
			for(int j = k; j <= n; j++)
				num[i][j] = k;

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				cout << setw(5) << num[i][j];
			cout << endl;
		}
		system("pause");
	}
	return 0;

}
