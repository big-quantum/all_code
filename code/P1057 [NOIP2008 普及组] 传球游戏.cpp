#include<bits/stdc++.h>
using namespace std;
int n,m,dp[35][35];
int main(){
	cin>>n>>m;
	dp[0][1]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(j==1) dp[i][j]=dp[i-1][n]+dp[i-1][j+1];
			else if(j==n) dp[i][j]=dp[i-1][j-1]+dp[i-1][1];
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
		}
	}
	cout<<dp[m][1]<<endl;
	return 0;
}
//https://www.luogu.com.cn/problem/P1057
