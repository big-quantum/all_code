#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, k, mp, g[1005], pr[1005], dp[105][105][105];

int main(){
	cin >> n >> k >> mp;
	for(int i = 1; i <= k; i++){
		cin >> g[i] >> pr[i];
	}
	dp[0][0][0] = 1;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			for(int p = 0; p <= mp; p++){
				dp[i][j][p] = dp[i - 1][j][p];
				if(j >= g[i]){
					dp[i][j][p] += dp[i - 1][j - g[i]][max(0, p - pr[i])] + 1;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans += dp[k][i][mp];
	}
	cout << ans << endl;
	return 0;
}
