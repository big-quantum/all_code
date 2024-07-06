#include<bits/stdc++.h>
using namespace std;
double x=0.0,l=2.0,n=0.0;
int ans=0;
int main(){
	cin>>x;
	while(n<x){
		n=n+l;
		l=l/100*98;
		ans++;
	} 
	cout<<ans<<endl;
	return 0;
}
