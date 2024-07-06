#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin >> n;	
	if (n % 400 == 0 || n % 100 != 0 && n % 4 == 0) cout << "Y" << endl;
	else cout << "N" << endl;
	return 0;
}
