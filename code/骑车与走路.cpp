#include<bits/stdc++.h>
using namespace std;
double a,b,w;
int main(){
	cin >> a;
	b = 23 + 27 + a / 3.0;
	w = a / 1.2;
	if (b > w) cout << "Walk" << endl;
	if (b == w) cout << "All" << endl;
	if (b < w) cout << "Bike" << endl;
	return 0;
}
