#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],n;
long long ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		ans=ans+a[i]*b[i];
	}
	cout<<ans<<endl;
	return 0;
}
