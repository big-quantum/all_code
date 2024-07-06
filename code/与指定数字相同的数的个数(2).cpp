#include<bits/stdc++.h>
using namespace std;
int n,m,ans,l[105];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	for(int i=1;i<=n;i++)
		if(l[i]==m)
			ans++;
	cout<<ans<<endl;
	return 0;
}
