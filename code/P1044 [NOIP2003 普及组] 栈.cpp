#include<bits/stdc++.h>
using namespace std;
int m;
int catalan(int n){
	int ans=0;
	if(n==0) return 1;
	if(n==1) return 1;
	for(int i=0;i<=n-1;i++){
		ans=ans+catalan(i)*catalan(n-i-1);
	}
	return ans;
}
int main(){
	cin>>m;
	cout<<catalan(m)<<endl;
	return 0;
}
