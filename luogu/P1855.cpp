#include<bits/stdc++.h>
using namespace std;

int n, m, t, v1[105], v2[105], dp[205][205];

int main(){
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++){
		cin >> v1[i] >> v2[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= v1[i]; j--){
			for(int k = t; k >= v2[i]; k--){
				dp[j][k] = max(dp[j][k], dp[j - v1[i]][k - v2[i]] + 1);
			}
		}
	}
	cout << dp[m][t] << endl;
	return 0;
}
