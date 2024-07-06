#include<bits/stdc++.h>
using namespace std;
int n,a[1005],dp[1005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[i]<=a[j]) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(dp[i],ans);
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1795
