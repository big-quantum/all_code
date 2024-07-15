#include<bits/stdc++.h>
using namespace std;

int n, a[205];
int dp[205][205];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int l = n - 2; l >= 1; l--){
		for(int r = l + 2; r <= n; r++){
			dp[l][r] = INT_MAX;
			for(int k = l + 1; k < r; k++){
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
