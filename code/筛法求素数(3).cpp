#include<bits/stdc++.h>
using namespace std;
int n;
bool p[210000000];
int main() {
	cin >> n;
	for(int i = 2; i <= n; i++)
		p[i] = 1;
	for(int i = 2; i <= n; i++) {
		if (p[i])
			for(int j = 2; j <= n / i; j++)
				p[i * j] = 0;
	}
	for(int i = 2; i <= n; i++)
		if (p[i])
			if (p[i+2])
				cout<<i<<' '<<i+2<<endl;
	return 0;
}
