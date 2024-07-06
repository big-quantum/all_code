#include<bits/stdc++.h>
using namespace std;
int n,dp[55],num[55];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	dp[1]=num[1];
	dp[2]=max(num[1],num[2]);
	for(int i=3;i<=n;i++){
		dp[i]=max(dp[i-2]+num[i],dp[i-1]);
	}
	cout<<dp[n]<<endl;
	return 0;
}
//https://oj.czos.cn/p/1653
