#include<bits/stdc++.h>
using namespace std;
int n;
bool yes;
bool check(int num) {
	if (num < 2)
		return false;
	for(int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;
	return true;
}
int main() {
	cin >> n;
	for(int t = 1; t <= n; t++) {
		yes = false;
		int num;		
		cin >> num;
		for(int i = 2; i <= num / 2; i++)
			if (check(i) && check(num - i)) {
				cout << num << "=" << i << "+" << num - i << endl;
				yes = true;
				break;
			}
		if (!yes)
			cout << "NO WAY!" << endl;
	}

	return 0;
}

