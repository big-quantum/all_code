#include<bits/stdc++.h>
using namespace std;
int n,w[201],dp[201],x,y;
bool a[201][201];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		dp[i]=w[i];
	}
    while(cin>>x>>y)
    {
    	if(x==0) break;
    	a[x][y]=1;
	}
	dp[1]=w[1];
	int ans=0;
	for(int i=2;i<=n;i++)
	    for(int j=1;j<i;j++)
		   if(a[j][i]) dp[i]=max(dp[i],dp[j]+w[i]);
	for(int i=1;i<=n;i++)
	   ans=max(ans,dp[i]);
	cout<<ans;
    return 0;
}


