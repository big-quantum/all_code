#include<bits/stdc++.h>
using namespace std;

int n, w[105], v[105];
long long dp[100005], space;

int main(){
	cin >> n >> space;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> v[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = space; j >= 0; j--){
			if(j >= w[i]){
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[space] << endl;
	return 0;
}
