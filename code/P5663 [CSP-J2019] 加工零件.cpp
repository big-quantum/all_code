#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct node{
	int u,v;
} graph[200005];
bool bfs(int x,int l){
	if(l==1) {
		for(int i=1;i<=2*m;i++){
			if(graph[i].u==x&&graph[i].v==1){
				return true;
			}
		}
		return false;
	}
	for(int i=1;i<=2*m;i++){
		if(graph[i].u==x){
			if(bfs(graph[i].v,l-1)) return true;
		}
	}
	return false;
} 
int main(){
	cin>>n>>m>>q;
	for(int i=1;i<=2*m;i+=2){
		cin>>graph[i].u>>graph[i].v;
		graph[i+1].u=graph[i].v;
		graph[i+1].v=graph[i].u;
	}
	for(int i=1;i<=q;i++){
		int a,l;
		cin>>a>>l;
		if(bfs(a,l)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
