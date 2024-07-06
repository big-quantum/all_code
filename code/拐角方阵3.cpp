#include<bits/stdc++.h> 
using namespace std;
int n,m,a[105][105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=j;
			a[j][i]=j;
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" "; 
		} 
		cout<<endl;
	}
} 
