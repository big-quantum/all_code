#include<bits/stdc++.h>
using namespace std;

int n, k, h[100005], dp[100005];

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
		for(int j = 2; j < i && j <= k; j++){
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << dp[n] << endl;
	return 0;
}
