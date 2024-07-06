#include<bits/stdc++.h>
using namespace std;
int w[1005],p[1005],f[5005],n,m;
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>p[i]; 
	}	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+p[i]);
		}
	}
	cout<<f[m];
	return 0;
}

