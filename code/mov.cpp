#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin >> a >> b >> c;
	if (a > b)
		swap(a,b);
	if (a > c)
		swap(a,c);
	if (b > c)
		swap(b,c);
	if (a + 2 == c)
		cout << 0 << endl;
	else
		if (a + 2 == b || b + 2 == c)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	cout << max(b - a - 1,c - b - 1) << endl;
	return 0;
}
