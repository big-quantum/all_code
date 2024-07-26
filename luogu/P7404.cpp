#include<bits/stdc++.h>
using namespace std;

long long n, a[200005], cf[200005];
long long ans;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cf[i] = a[i] - a[i - 1];
	}
	int l = 1, r = n;
	while(l < r){
		while(cf[l] > 0) l++;
		while(cf[r] < 0) r--;
		if(l > r) break;
		long long tmp = min(1 - cf[l], 1 + cf[r]);
		cf[l] += tmp;
		cf[r] -= tmp;
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}
