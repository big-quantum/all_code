#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
	cin>>n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			ans=n/i;
		}
	}
	cout<<ans<<endl;
	return 0;
}