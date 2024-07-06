#include<bits/stdc++.h>
using namespace std;
int m,k,n;
int main(){
	cin>>m>>k;
	if(m%19==0)while(m){
		if(m%10==3)
		n++;
		m=m/10;
	}
	if(n==k)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;	
}


