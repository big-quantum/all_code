#include<bits/stdc++.h>
using namespace std;

int n, w[105], v[105], tot, ans;
long long dp[100005], space;

int main(){
	memset(dp, 0x3f, sizeof(dp));
	cin >> n >> space;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];
		tot += v[i];
	}
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = tot; j >= 0; j--){
			if(j >= v[i]){
				dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
			}
		}
	}
	for(int i = 0; i <= tot; i++){
		if(dp[i] <= space) ans = max(i, ans);
	}
	cout << ans << endl;
	return 0;
}
