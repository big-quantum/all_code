#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			if (i > j)
				cout << setw(5) << j;
			else 
				cout << setw(5) << i;			
		cout << endl;
	}
	return 0;
}
