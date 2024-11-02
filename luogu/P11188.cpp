#include<bits/stdc++.h>
using namespace std;

int t, c, v[10], n;
string s;
long long long_long_max = 1e18, dp[100005][7];

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}

int main(){
	cin >> c;
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		for(int i = 1; i <= 9; i++){
			cin >> v[i];
		}
		reverse(s.begin(), s.end());
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < 7; i++){
			dp[n][i] = long_long_max;
		}
		s = " " + s;
		for(int i = 1; i <= n; i++){
			dp[i][0] = dp[i - 1][0] + v[s[i] - '0'];
			for(int j = 1, t = 1; j < 7; j++, t *= 10){
				dp[i][j] = min(dp[i - 1][j - 1] + t * (s[i] - '0'), dp[i - 1][j] + v[s[i] - '0']);
			}
		}
		long long ans = long_long_max;
		for(int i = 0; i < 7; i++){
			ans = min(ans, dp[n][i]);
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
