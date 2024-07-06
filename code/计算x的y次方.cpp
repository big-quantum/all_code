#include<bits/stdc++.h>
using namespace std;
int x,y;

int P(int x,int y) {
	if (y == 0)
		return 1;
	else 
		return x * P(x,y - 1);
}
int main() {
	cin >> x >> y;
	cout << P(x,y) << endl;
	return 0;
}

