#include<bits/stdc++.h>
using namespace std;
int a,b,n,ans;
int main(){
	cin>>a>>b;
	n=b-a;
	ans=(1+n)*n/2-b;
	cout<<ans<<endl;
	return 0;
}
