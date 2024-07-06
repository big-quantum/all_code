#include<bits/stdc++.h>
using namespace std;
int x,y,m,ans;
int main(){
	cin>>x>>y>>m;
	for(int i=0;i<=m/x;i++)
		for(int j=0;j<=m/y;j++)
			if(i*x+j*y<=m&&i*x+j*y>ans)
				ans=i*x+j*y;
	cout<<ans<<endl;
	return 0;
}

