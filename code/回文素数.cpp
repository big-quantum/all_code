#include<bits/stdc++.h>
using namespace std;
long long n;
bool y;
int main() {
	cin >> n;
	for(long long i = 2; i <= n; i++) {
		y = true;
		for(long long j = 2; j <= sqrt(i); j++)//平方根i 
			if (i % j == 0) {
				y = false;
				break;//退出 
			}
		if (y) {
			int num = i,n = 0;
			while(num) {
				n = n * 10 + num % 10;
				num /= 10;
			}
			if (n == i) cout << i << " ";
		}
	}
	return 0;
}


