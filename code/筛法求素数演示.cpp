#include<bits/stdc++.h>
using namespace std;
#define Maxn 1000000
int n,p[Maxn + 5];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		p[i] = 1;
		cout << setw(3) << i;
	}
	cout << endl;
	p[1] = 0;
	for(int i = 1; i <= n; i++)
		cout << setw(3) << p[i];
	cout << endl;
	for(int i = 2; i <= n; i++) {
		if (p[i])
			for(int j = 2; j <= n / i; j++)
				p[i * j] = 0;
		for(int j = 1; j <= n; j++)
			cout << setw(3) << p[j];
		cout << endl;
		system("pause");
	}


	return 0;

}

