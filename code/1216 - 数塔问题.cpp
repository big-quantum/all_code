#include<bits/stdc++.h>
using namespace std;
int n,star[105][105],dp[105][105],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>star[i][j];
		} 
	}
	dp[1][1]=star[1][1];
	for(int i=2;i<=n;i++){
		dp[i][1]=dp[i-1][1]+star[i][1];
		dp[i][i]=dp[i-1][i-1]+star[i][i];
		for(int j=2;j<i;j++){
			dp[i][j]=max(dp[i-1][j]+star[i][j],dp[i-1][j-1]+star[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1216
