#include<bits/stdc++.h>
using namespace std;
int t,j,to,y,jz,tz,yz,zns;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>j>>y>>to;
		jz=jz+j;
		tz=tz+to;
		yz=yz+y;
	}
	zns=jz+tz+yz;
	cout<<jz<<" "<<yz<<" "<<tz<<" "<<zns<<endl;
}
