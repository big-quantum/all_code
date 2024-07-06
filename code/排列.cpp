#include<bits/stdc++.h>
using namespace std;
int n,a[10];
bool use[100];
void dfs(int k){
	if(k==n+1){
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;
	} else {
		for(int i=1;i<=n;i++){
			if(use[i]==0){
				use[i]=1;
				a[k]=i;
				dfs(k+1); 
				use[i]=0;
			}
		} 
	}
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
}
