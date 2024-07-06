#include<bits/stdc++.h>
using namespace std;
int n,a[105][105],ans,b[105][105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	} 
	for(int i=1;i<=n;i++){
		b[i][1]=a[i][1]+b[i-1][1];
		for(int j=2;j<i;j++){
			 b[i][j]=max(a[i][j]+b[i-1][j],a[i][j]+b[i-1][j-1]);
		}
		b[i][i]=a[i][i]+b[i-1][i-1];
	}  
	for(int i=1;i<=n;i++){
		if(b[n][i]>ans) ans=b[n][i];
	}
	cout<<ans<<endl; 
	return 0;
}
