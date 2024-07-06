#include<bits/stdc++.h>
using namespace std;

long long a,b,c;

int main() {
	cin >> a >> b >> c;
	if(c == a + b) cout << "plus" << endl;
	else if(c == a - b) cout << "minus" << endl;
	else cout << "illegal" << endl;
	return 0;
}
