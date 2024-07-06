#include<bits/stdc++.h>
using namespace std;
int n,k,x;
int main(){
	cin >> n;
	for(x = 100;x >= 1;x--){
		k = (n / 52 - 7 * x) / 21;
		if (k > 0 && (7 * x + 21 *k) * 52 == n){
			cout << x << endl << k << endl;
			return 0;
		} 
	}
	
	return 0;
}
