#include<bits/stdc++.h>
using namespace std;
int n,s[5],j[5],q,boss=2100000000;
int main(){
	cin>>n;
	for(int i=1;i<=3;i++)
		cin>>s[i]>>j[i];
	for(int i=1;i<=3;i++){
		if(n%s[i]!=0)
			q=n/s[i]+1;
		if(boss>q*j[i])
			boss=q*j[i];
	}
	cout<<boss<<endl;
	return 0;
}
