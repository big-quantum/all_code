#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,t;
int in[100005],dis[100005][12],ans;
bool vis[100005];
struct node{
	int v,w;
	node(int _v,int _w){
		v=_v;
		w=_w;
	};
	friend bool operator > (node a,node b) 
	{
		return a.w>b.w;
	}
};
vector<node> gra[100005];

int main() {
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m>>k;
	cin>>s>>t;
	dis[s][k]=0;
	for(int i=1; i<=m; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		gra[a].push_back(node(b,c));
		gra[b].push_back(node(a,c));
	}
	priority_queue<node,vector<node>,greater<node> >q;
	q.push(node(s,0));
	while(!q.empty()) {
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=1; i<=gra[u].size();i++) {
			int v=gra[u][i].v;
			if(dis[v][k]>dis[u][k]+gra[u][i].w/*||dis[v][k]>dis[u][k-1]*/){
				//dis[v][k]=min(dis[u][k]+gra[u][i].w,dis[u][k-1]);	
				dis[v][k]=dis[u][k]+gra[u][i].w;
				q.push(node(v,dis[v][k]));
			}
		}
	}
	for(int i=1;i<=k;i++){
		ans=min(ans,dis[t][i]);
	}
	cout<<dis[t][k]<<endl;
	return 0;
}
