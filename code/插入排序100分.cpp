#include<bits/stdc++.h>
using namespace std;
int n,q,a[8005],b[8005],num,x,v,ans;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==j||a[j]<a[i]||a[j]==a[i])b[i]++;
			else b[j]++;
		}//这里的b[i]就是第i个数在数组a[i]中的排位 
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d",&num);
		if(num==1)
		{
			scanf("%d%d",&x,&v);
			for(int i=1;i<=n;i++)
			{
				if(i==x)continue;
				if((a[i]<a[x]||a[i]==a[x]&&i<x)&&(a[i]>v||a[i]==v&&i>x))
				{
					b[i]++;b[x]--;
				}
				else if((a[i]>a[x]||a[i]==a[x]&&i>x)&&(a[i]<v||a[i]==v&&i<x))
				{
					b[i]--;b[x]++;
				}
			}
			a[x]=v;
		}
		if(num==2)
		{
			scanf("%d",&x);
			printf("%d\n",b[x]);
		}
	}
	return 0;
}
