#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int main(){
	cin>>m>>n;
	for(int i=m;i<=n;i++)
		if(i%17==0)
			ans=i+ans;
	cout<<ans<<endl; 
	return 0;
} 
