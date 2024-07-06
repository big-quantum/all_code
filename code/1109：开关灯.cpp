#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
bool light[5005];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		light[i]=true;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j%i==0) if(light[j]==true) light[j]=false;
					   else light[j] = true;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(light[i]==false)
		{
			ans=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(light[i]==false) if(i!=ans) cout<<i<<",";
	}
	cout<<ans<<endl;
	return 0;
}
