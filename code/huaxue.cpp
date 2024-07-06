#include<bits/stdc++.h>
using namespace std;
int r,c,dp[10001],k=1;
struct ski
{
	int x;
	int y;
	int h;
}s[10001];
bool cmp1(ski a,ski b)
{
	return a.h<b.h;
}
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	   for(int j=1;j<=c;j++)
	    {
	      s[k].x=i;
		  s[k].y=j;
		  cin>>s[k].h;
		  k++;	
		}
	k--;
	sort(s+1,s+k+1,cmp1);
	int maxn=0;
	for(int i=k;i>=1;i--)
	{
		dp[i]=1;
		for(int j=i+1;j<=k;j++)
	   	    if(abs(s[i].x-s[j].x)+abs(s[i].y-s[j].y)==1&&s[i].h<s[j].h) dp[i]=max(dp[i],dp[j]+1);
	    maxn=max(dp[i],maxn);
	}
	cout<<maxn;   
    return 0;
}

