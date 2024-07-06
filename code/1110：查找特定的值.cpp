#include<bits/stdc++.h>
using namespace std;
int n,number[10005],x,ans;
bool flag;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>number[i];	
	} 
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		if(number[i]==x)
		{
			flag=true;
			ans=i;
			break;
		} 
	}
	if(flag)
	{
		cout<<ans<<endl;
	} else {
		cout<<-1<<endl;
	}
}
