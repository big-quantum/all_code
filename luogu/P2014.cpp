#include<bits/stdc++.h>
using namespace std;

int n, m, t, s[305], dp[305][305];
vector<int> edge[305];

void solve(int x){
	for(auto i : edge[x]){
		solve(i);
	}
	for(auto i : edge[x]){
		for(int j = m + 1; j > 0; j--){
			for(int k = 0; k < j; k++){
				dp[x][j] = max(dp[x][j], dp[i][k] + dp[x][j - k]);
			}
		}
	}
}

int main(){
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
		int from;
		cin >> from >> dp[i][1];
		edge[from].push_back(i);
	}
	solve(0);
	cout << dp[0][m + 1] << endl;
	return 0;
}
