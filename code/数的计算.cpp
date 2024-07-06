#include<bits/stdc++.h>
using namespace std;
int n,ans;
void dns(int n){
	ans++;
	for(int i=1;i<=n/2;i++)
		dns(i);
}
int main(){
	cin>>n;
	dns(n);
	cout<<ans<<endl;
	return 0;
}
