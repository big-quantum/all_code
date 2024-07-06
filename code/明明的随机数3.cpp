#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		if(a[b]!=1){
			a[b]=1;
			m++;	
		}
	} 
	cout<<m<<endl;
	for(int i=1;i<=1005;i++){
		if(a[i]==1){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
} 
