#include<bits/stdc++.h>
using namespace std;
int n,c[105][105];
int main(){
	cin>>n;
	c[0][0]=1;
	c[1][0]=1;
	c[1][1]=1;
	for(int i=2;i<n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
