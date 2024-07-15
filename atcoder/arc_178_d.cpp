#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

int n, m, a[505], pos[505];
long long dp[505][505][505];


int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	
	if(pos[0] == 0){
		for(int i = 1; i <= n; i++){
			dp[i][i][0] = 1;
		}
	} else {
		dp[pos[0]][pos[0] + 1][0] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		if(pos[i] == 0){
			for(int r = 1; r <= m + 1; r++){
				long long tmp = 0;
				for(int l = r; l >= 1; l--){
					tmp = (tmp + dp[l][r][i - 1]) % mod;
					dp[l][r][i] = (dp[l][r][i] + tmp) % mod;
				}
			}
			for(int l = 1; l <= m + 1; l++){
				long long tmp = 0;
				for(int r = l; r <= m + 1; r++){
					tmp = (tmp + dp[l][r][i - 1]) % mod;
					dp[l][r][i] = (dp[l][r][i] + tmp) % mod;
				}
			}
		} else {
			for(int l = 1; l <= m + 1; l++){
				for(int r = l; r <= m + 1; r++){
					dp[min(l, pos[i])][max(r, pos[i] + 1)][i] = (dp[min(l, pos[i])][max(r, pos[i] + 1)][i] + dp[l][r][i - 1]) % mod;
				}
			}
		}
	}
	cout << dp[1][m + 1][n - 1] << endl;
	return 0;
}
