#include<bits/stdc++.h>
using namespace std;
#define Maxn 1000000
int n,p[Maxn + 5],ans;
int main() {
	cin >> n;
	for(int i = 2; i <= n; i++)
		p[i] = 1;
	for(int i = 2; i <= n; i++) {
		if (p[i])
			for(int j = 2; j <= n / i; j++)
				p[i * j] = 0;	
	}
	for(int i = 2;i <= n;i++)
		if (p[i]) ans++;
	cout <<ans<< endl;
	return 0;
}
