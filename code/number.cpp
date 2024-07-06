#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<8;i++)
	{
		if(s[i]=='1')
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
 
