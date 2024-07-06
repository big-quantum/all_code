#include<bits/stdc++.h>
using namespace std;
int a[11],n,ans;
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
		a[k]=i;
		dfs(k+1);
	}
} 
int main(){
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

