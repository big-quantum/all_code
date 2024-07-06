#include<bits/stdc++.h>
using namespace std;
int n,k,m,s,t,c[105];
bool a[105][105];
struct node{
	int v,d;
}country[205];
void dfs(){
	
}
int main(){
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		node tmp;
		int u;
		cin>>u>>tmp.v>>tmp.d;
		if(country[u].d!=0&&country[u].d>tmp.d){
			if(!a[u][tmp.v]){
				country[u].d=tmp.d;
			}
			if(!a[tmp.v][u]){
				country[country[u].v].d=tmp.d;	
			}
		} else {
			if(!a[u][tmp.v]){
				country[u].v=tmp.v;
				country[u].d=tmp.d;
			}
			if(!a[tmp.v][u]){
				country[tmp.v].v=u;
				country[tmp.v].d=tmp.d;
			}
		}
	}
	
	return 0;
} 
