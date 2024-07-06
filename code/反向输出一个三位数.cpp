#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main() {
	cin >> n;
	a = n % 10;
	b = n / 10 % 10;
	c = n / 100;;
	cout << a << b << c << endl;
	return 0;
}
