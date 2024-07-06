#include<bits/stdc++.h>
using namespace std;
int n,a,ans,tail;
int main(){
	freopen("drink.in","r",stdin);
	freopen("drink.out","w",stdout);
	cin>>n>>tail;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(tail>=a) ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
