#include<bits/stdc++.h>
using namespace std;
int n,a[10005],dp[10005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<=a[i]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1794
