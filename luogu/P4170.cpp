#include<bits/stdc++.h>
using namespace std;

int n, dp[55][55];
string s;

int main(){
	cin >> s;
	n = s.size();
	for(int i = 0; i <= n + 2; i++){
		for(int j = 0; j <= n + 2; j++){
			dp[i][j] = INT_MAX;
		}
	}
	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
	}
	for(int len = 2; len <= n; len++){
		for(int i = 0; i + len - 1 < n; i++){
			int j = i + len - 1;
			if(s[i] == s[j]) dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			else {
				for(int k = i; k < j; k++){
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
