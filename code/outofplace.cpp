#include<bits/stdc++.h>
using namespace std;
#define Maxn 100 + 5
int a[Maxn],b[Maxn],n,ans;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			if (a[i] > a[j])
				swap(a[i],a[j]);
	for(int i = 1; i <= n; i++)
		if (a[i] != b[i])
			ans++;
	cout << ans - 1 << endl;
	return 0;
}
