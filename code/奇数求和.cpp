#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int main(){
	cin>>m>>n;
	for(int i=m;i<=n;i++)
		if(i%2==1) ans=ans+i;
	cout<<ans<<endl;
}
