#include<bits/stdc++.h>
using namespace std;
int n,a[105],b[105],ans;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1,b + 1 + n);
	for(int i = 1;i <= n;i++)
		if (a[i] != b[i])
			ans++;
	cout << ans - 1 << endl;
	return 0;
}
