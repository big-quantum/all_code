#include<bits/stdc++.h>
using namespace std;
int x,n,ans,m;
int main(){
	cin>>x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		ans=ans+x-m;
	}
	ans=ans+x;
	cout<<ans<<endl;
	return 0;
}
