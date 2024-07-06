#include<bits/stdc++.h>
using namespace std;

long long n, m, p, q;
long long spd, spf;

int main() {
	cin >> n >> m >> p >> q;
	
	spd = n * m;
	spf = p * q;
	
	if(spd >= spf) cout << "Program ends with return value 0." << endl;
	else cout << "Segmentation fault." << endl;
	
	return 0;
}
