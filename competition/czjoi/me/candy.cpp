#include<bits/stdc++.h>
using namespace std;

long long n, l, r, a[200005], d, sum[200005];
vector<long long> t;
long long ans1, ans2;

long long gcd(long long a, long long b){
	if(b != 0) return gcd(b, a % b);
	else return a;
}

int main(){
	cin >> n >> l >> r;
	for(int i = 1; i < n; i++){
		cin >> a[i];
		a[i + n] = a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	cin >> a[n];
	for(int i = n - 1; i < 2 * n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(l += l % 2; l <= r; l += 2){
		for(int i = 1; i <= n; i++){
			if(i + l - 1 >= 2 * n) break;
			long long tot = sum[i + l - 1] - sum[i - 1];
			long long gg = gcd(tot, l), ll = l / gg;
			tot /= gg;
			if(ans1 == 0 || ans2 * tot > ans1 * ll){
				ans1 = tot;
				ans2 = ll;
			} 
		}
	}
	if(ans2 != 1) cout << ans1 << "/" << ans2 << endl;
	else cout << ans1 << endl;
	return 0;
}
