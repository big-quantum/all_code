#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin >> n;	
	if (n % 3 == 0) cout << "3 ";
	if (n % 5 == 0) cout << "5 ";
	if (n % 7 == 0) cout << "7";
	if (n % 3 != 0 && n % 5 != 0 && n % 7 != 0) cout << "n";
	cout << endl;
	return 0;
}
