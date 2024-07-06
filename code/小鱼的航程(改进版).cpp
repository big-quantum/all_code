#include<bits/stdc++.h>
using namespace std;
long long x=0,n=0,ans=0;
int main(){
	cin>>x>>n;
	for(int i=1;i<=n;i++){
		if((x!=6)&&(x!=7)){
			ans=ans+250;
		} 
		if(x==7) x=1; 
		else x++;
	}
	cout<<ans<<endl;
	return 0;
}
