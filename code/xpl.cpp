#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[11],tot;
bool b[11];
void dfs(int k){
	if(k>m){
		ans++;
		for(int i=1;i<=m;i++){
			cout<<a[i];
		}
		cout<<endl;
		return;
	} 
	for(int i=1;i<=n;i++){
		if(!b[i]){
			a[k]=i;
			b[i]=true;
			dfs(k+1);
			b[i]=false;
		}
	} 
}
int main(){
	cin>>n>>m;
	dfs(1);
	cout<<ans;
	return 0;
}

