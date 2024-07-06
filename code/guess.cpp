#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int num){
	if (num < 2)
		return false;
	for(int i = 2;i <= sqrt(num);i++)
		if (num % i == 0)
			return false;
	return true;
}
int main() {
	cin >> n;
	for(int i = 2; i <= n / 2; i++)
		if (check(i) && check(n - i)) 
			cout << n << "=" << i << "+" << n - i << endl;
	return 0;
}
