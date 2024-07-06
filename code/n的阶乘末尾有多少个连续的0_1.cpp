#include<bits/stdc++.h>
using namespace std;
int n,a;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int u = i;
		while(u % 5 == 0) {
			u = u / 5;
			a++;
		}
	}
	cout << a << endl;
	return 0;
}
