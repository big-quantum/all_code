#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main() {
	cin >> d;
	a = d % 10;
	b = d / 10 % 10;
	c = d / 100;
	cout << a << b << c << endl;
	return 0;
}
