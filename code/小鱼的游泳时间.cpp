#include<bits/stdc++.h>
using namespace std;
int am,bh,cm,dh,em,fh,f;
int main() {
	cin >> bh >> am >> dh >> cm;
	f=(dh*60+cm)-(bh*60+am);
	fh=f/60;
	em=f%60;
	cout << fh << " " << em << endl;
	return 0;
}
