#include<bits/stdc++.h>
using namespace std;
int n,a[1005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans+=max(0,a[i]-10);
	}
	cout<<ans<<endl;
	return 0; 
} 
