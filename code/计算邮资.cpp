#include<bits/stdc++.h>
using namespace std;
int w,m;
char ch;
int main(){
	cin >> w >> ch;
	m = 8;
	if (w > 1000){
		m = m + (w - 1000) / 500 * 4;
		if ((w - 1000) % 500) m = m + 4;
	}	
	if (ch == 'y') m += 5;
	cout << m << endl;
	return 0;
}



