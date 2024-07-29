#include<bits/stdc++.h>// 二进制分组优化 
using namespace std;

int n, m, dp[100005];
int w[1005], v[1005], e[1005], cnt;

int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		for(int j = 1; j <= c; j *= 2){
			v[++cnt] = a * j;
			w[cnt] = b * j;
			c -= j;
		}		
		if(c){
			v[++cnt] = a * c;
			w[cnt] = b * c;
		} 
	}
	for(int i = 1; i <= cnt; i++)
		for(int j = m; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[m] << endl;
	return 0;
} 
