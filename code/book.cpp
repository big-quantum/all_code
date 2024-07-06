#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,ans;
int main(){
	cin>>a>>b>>x>>y;
	if(x<y){
		int n;
		n=x;
		x=y;
		y=n;
	}
	if(a<y) ans+=(y-a);
	else ans+=(a-y);
	if(b>x) ans+=(b-x);
	else ans+=(x-b);
	cout<<ans<<endl;
} 
