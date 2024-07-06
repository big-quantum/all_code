#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c;
int main(){
	cin>>n;
	a=b=1;
	for(int i=3;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	if (n<3) cout<<1;
	else cout<<c;
	return 0;
}
