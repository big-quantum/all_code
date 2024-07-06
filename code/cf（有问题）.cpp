#include<bits/stdc++.h>
using namespace std;
int a[11],n,ans;
void dfs(int k,int s){
	if(s==0){
		for(int i=1;i<=k-1;i++){
			if(a[i]!=n){
				ans++;
				for(int j=1;j<=k-1;j++){	
					cout<<a[i];
				}
				cout<<endl;
				return;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		if(i<=s&&i>=a[k-1]){
			a[k]=i;
			s=s-i;
			dfs(k+1,s);
			s=s+i;
		} 
	} 
}
int main(){
	cin>>n;
	dfs(1,n);
	cout<<ans;
	return 0;
}

