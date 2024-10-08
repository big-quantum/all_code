#include<bits/stdc++.h>
using namespace std;

int n, m, t, v1[105], v2[105], dp[1005][505];

int main(){
	cin >> m >> t >> n;
	for(int i = 1; i <= n; i++){
		cin >> v1[i] >> v2[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= v1[i]; j--){
			for(int k = t - 1; k >= v2[i]; k--){
				dp[j][k] = max(dp[j][k], dp[j - v1[i]][k - v2[i]] + 1);
			}
		}
	}
	int cost = t;
	for(int i = 0; i <= t; i++){
		if(dp[m][i] == dp[m][t - 1]) cost = min(cost, i);
	}
	
	cout << dp[m][t - 1] << " " << t - cost << endl;
	
	return 0;
}
