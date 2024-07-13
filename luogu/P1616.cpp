#include<bits/stdc++.h>
using namespace std;

long long t, m, dp[10000005], w[10005], tim[10005];

int main(){
	cin >> t >> m;
	for(int i = 1; i <= m; i++){
		cin >> tim[i] >> w[i]; 
	}
	for(int i = 1; i <= m; i++){
		for(int j = tim[i]; j <= t; j++){
			dp[j] = max(dp[j], dp[j - tim[i]] + w[i]);
		}
	}
	
	cout << dp[t] << endl;
	return 0;
} 
