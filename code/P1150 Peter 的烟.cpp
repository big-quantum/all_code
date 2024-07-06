#include<bits/stdc++.h>
using namespace std;
int n,k,ans,s;
int main(){
	cin>>n>>k;
	ans=n;
	while(n>=k){
		ans+=(n/k);
		n=n%k+n/k;
	}
	cout<<ans<<endl;
	return 0;
} 
