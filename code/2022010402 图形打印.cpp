#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n+i-1;j++){
			if(n-j-i+1>0) cout<<" ";
			else cout<<"*"; 
		}
		cout<<endl;
	}
	for(int i=1;i<=2*n-1;i++) cout<<"*";
	cout<<endl;
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=n+i-1;j++){
			if(n-j-i+1>0) cout<<" ";
			else cout<<"*"; 
		}
		cout<<endl;
	}
	return 0;
} 
