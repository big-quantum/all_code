#include<bits/stdc++.h>
using namespace std;
int n,dp[105],num[105][2],ans;
int main(){
	cin>>n;
	cin>>num[1][0];
	num[1][1]=num[1][0];
	for(int i=2;i<=n;i++){
		cin>>num[i][0];
		//num[i][1]=num[i-1][1]+num[i][0];
	}
	dp[1]=num[1][0];
	/*for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[j]=max(dp[j-1],num[j][1]-num[i][1]);
		}
	}*/
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i-1]+num[i][0],num[i][0]);
		ans=max(dp[i],ans);
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1589
