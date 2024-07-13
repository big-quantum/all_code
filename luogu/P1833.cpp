#include<bits/stdc++.h>
using namespace std;

int n, c[10005], tmin, th, h, m, t[10005], p[10005], dp[10005];

int main(){
	scanf("%d:%d %d:%d %d", &h, &m, &th, &tmin, &n);
	int tim = (th - h) * 60 + tmin - m;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> c[i] >> p[i]; 
	}
	for(int i = 1; i <= n; i++){
		if(p[i] == 0){
			for(int j = t[i]; j <= tim; j++){
				dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
			}
		} else {
			for(int k = 1; k <= p[i]; k++)
				for(int j = tim; j >= t[i]; j--){
					dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
				}
		}
	}
	
	cout << dp[tim] << endl;
	return 0;
} 
