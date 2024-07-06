#include<bits/stdc++.h>
using namespace std;
int n,a[105],maxnumber=-100000000,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(maxnumber<a[i]) maxnumber=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=maxnumber) ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
