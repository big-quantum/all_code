#include<bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005];
long long ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		ans=ans+a[i]*b[i];
	}
	cout<<ans<<endl;
	return 0;
}
