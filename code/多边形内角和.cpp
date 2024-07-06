#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
int main(){
	cin>>n;
	for(int i=1; i<=n-1;i++){
		cin>>a;
		ans=ans+a;
	}
	n=(n-2)*180;
	cout<<n-ans<<endl;
	return 0;
}
