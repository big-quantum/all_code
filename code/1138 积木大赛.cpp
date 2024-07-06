#include<bits/stdc++.h>
using namespace std;
int n,a,ans,b;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>b) ans=ans+a-b;
		b=a;
	}
	cout<<ans<<endl;
	return 0;
} 
