#include<bits/stdc++.h>
using namespace std;
int a[11],n,tot;
void dfs(int k){
	if(k>n){
		tot++;
		for(int i=1;i<=n;i++){
			cout<<a[i];
		} 
		cout<<endl;
	} else {
		for(int i=1;i<=n;i++){
			a[k]=i;
			dfs(k+1);
		}
	}
} 
int main(){
//	iso::sync_with_stido(false); 
	cin>>n;
	dfs(1);
	cout<<tot<<endl;
	return 0;
}
