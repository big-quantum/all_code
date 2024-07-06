#include<bits/stdc++.h>
using namespace std;
int maxw,n,w[105],v[105],dp[105][20005];
int main(){
	cin>>maxw>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxw;j++){
			if(j>=w[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[n][maxw]<<endl;
	return 0;
} 
//https://oj.czos.cn/p/1282
