#include<bits/stdc++.h>
using namespace std;

int n, m, dp[100005];
int w[105], v[105], e[105];

int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> v[i] >> w[i] >> e[i]; 
	}
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= e[i]; k++)
			for(int j = m; j >= w[i]; j--){
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
	}
	
	cout << dp[m] << endl;
	return 0;
} 
