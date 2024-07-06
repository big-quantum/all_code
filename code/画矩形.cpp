#include<bits/stdc++.h>
using namespace std;
int m,n,b;
char ch;
int main() {
	cin >> m >> n >> ch >> b;
	if (b)
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++)
				cout << ch;
			cout << endl;
		}
	else {
		for(int j = 1;j <= n;j++)
			cout << ch;
		cout << endl;
		for(int i = 2;i <= m - 1;i++){
			cout << ch;
			for(int j = 2;j <= n - 1;j++)
				cout << " ";
			cout << ch << endl;
		}
		for(int j = 1;j <= n;j++)
			cout << ch;
		cout << endl;
	}
	return 0;
}
