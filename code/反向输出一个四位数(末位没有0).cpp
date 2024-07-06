#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d;
int main() {
	cin >> n;
	a = n % 10;
	b = n / 10 % 10;
	c = n / 100 % 10;
	d = n / 1000;
	cout << a * 1000 + b * 100 + c * 10 + d << endl;
	return 0;
}
