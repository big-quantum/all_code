#include<bits/stdc++.h>
using namespace std;
int a[15],n,tot;
bool p[15],c[20],d[20];
void dfs(int k){
	if(k>n){
		tot++;
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	} else {
		for(int i=1;i<=n;i++){
			if(!p[i]&&!c[i+k]&&!d[i-k+n]){
				a[k]=i;
				p[i]=true;
				c[i+k]=true;
				d[i-k+n]=true;
				dfs(k+1);
				p[i]=false;
				c[i+k]=false;
				d[i-k+n]=false;
			}
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<tot<<endl; 
	return 0;
}
