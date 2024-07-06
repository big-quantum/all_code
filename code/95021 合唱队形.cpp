#include<bits/stdc++.h>
using namespace std;
int n,a[105],f[105][2],ans=10000; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j]) f[i][0]=max(f[j][0]+1,f[i][0]);
		} 
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i;j<=n;j++){
			if(a[i]>a[j]) f[i][1]=max(f[j][1]+1,f[i][1]);
		} 
	}
	for(int i=1;i<=n;i++){
		ans=min(ans,n-f[i][0]-f[i][1]-1);
	}
	cout<<ans<<endl;
	return 0;
}
