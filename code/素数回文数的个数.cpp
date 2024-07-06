#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool yes;
int main() {
	cin >> n;
	for(int i = 11; i <= n; i++) {
		yes = true;
		for(int j = 2; j <= sqrt(i); j++)
			if (i % j == 0) {
				yes = false;
				break;
			}
		if (yes) {
			int num = i,newn = 0;
			while(num) {
				newn = newn * 10 + num % 10;
				num /= 10;
			}
			if (newn == i) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}



