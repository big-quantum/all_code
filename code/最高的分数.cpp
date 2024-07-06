#include<bits/stdc++.h>
using namespace std;
int n,ans=0,f;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f;
		if(f>ans)
		ans=f;
	}
	cout<<ans;
	return 0;
}
