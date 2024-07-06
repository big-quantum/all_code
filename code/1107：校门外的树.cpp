#include<bits/stdc++.h>
using namespace std;
int L,M1,M2,M,ans;
bool road[10005];
int main()
{
	cin>>L>>M;
	for(int i=0;i<=L;i++)
	{
		road[i]=true;
	}
	for(int i=0;i<M;i++)
	{
		cin>>M1>>M2;
		for(int j=M1;j<=M2;j++)
		{
			road[j]=false;
		}
	}
	for(int i=0;i<=L;i++)
	{
		if(road[i]==true) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
