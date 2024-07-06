#include<bits/stdc++.h>
using namespace std;
int n,ans,a[11],tot;
bool b[11];
void dfs(int k){
	if(k>n){
		ans++;
		for(int i=1;i<=n;i++){
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
	cin>>n;
	dfs(1);
	cout<<ans;
	return 0;
}

