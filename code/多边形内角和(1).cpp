#include<bits/stdc++.h>
using namespace std;
int n,g,ans;
int main(){
	cin>>n;
	ans=(n-2)*180;
	n=n-1;
	for(int i=1;i<=n;i++){
		cin>>g;
		ans=ans-g;
	}
	cout<<ans<<endl;
}
