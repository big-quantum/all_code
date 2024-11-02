#include<bits/stdc++.h>
using namespace std;

int n, h[100005], dp[100005];

int main(){
	cin >> n;
	cin >> h[1] >> h[2];
	dp[1] = 0;
	dp[2] = abs(h[1] - h[2]);
	for(int i = 3; i <= n; i++){
		cin >> h[i];
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	}
	cout << dp[n] << endl;
	
	return 0;
}
