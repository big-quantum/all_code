#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d;
int main() {
	cin >> n;
	a = n % 10;
	b = n / 10 % 10;
	c = n / 100 % 10;
	d = n / 1000;
	cout << a << b << c << d << endl;
	return 0;
}
