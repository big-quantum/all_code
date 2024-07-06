#include<bits/stdc++.h>
using namespace std;
int n,x,a[100005],ans;
int dp[100005];
int main(){
	cin>>n>>x;
	a[1]=x;
	dp[1]=x;
	for(int i=2;i<=n;i++){
		a[i]=(379*a[i-1]+131)%997;
	}
	for(int i=2;i<=n;i++){
		dp[i]=min(a[i],dp[i-1]);
	}
	for(int i=1;i<=n;i++){
		ans+=dp[i];
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1650
