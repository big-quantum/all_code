#include<bits/stdc++.h>
using namespace std;

int n, a[305];
long long dp[305][305], s[305];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for(int l = 1; l <= n; l++){
		for(int r = 1; r <= n; r++){
			if(l != r) dp[l][r] = INT_MAX;
		}
	}
	for(int len = 2; len <= n; len++){
		for(int l = 1; l + len - 1 <= n; l++){
			int r = l + len - 1;
			for(int k = l; k < r; k++){
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}
	
	cout << dp[1][n] << endl;
	return 0;
}
