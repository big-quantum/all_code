#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		long long b;
		cin>>b;
		ans=(ans*(b+1))%998244353;
	}
	cout<<ans<<endl; 
	return 0;
} 
