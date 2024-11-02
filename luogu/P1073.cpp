#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, m, val[MAXN], u[MAXN], v[MAXN], flag[MAXN], scc_val_max[MAXN], scc_val_min[MAXN];
vector<int> graph[MAXN], edge[MAXN];
int stk[MAXN], top, scc_cnt, id[MAXN], in[MAXN];
bool instk[MAXN];
int times, low[MAXN], dfn[MAXN], dp[MAXN];

void tarjan(int u){
	low[u] = dfn[u] = ++times;
	instk[u] = true;
	stk[++top] = u;
	for(auto i : graph[u]){
		if(!dfn[i]){
			tarjan(i);
			low[u] = min(low[i], low[u]);
		} else if(instk[i]){
			low[u] = min(dfn[i], low[u]);
		}
	}
	if(low[u] == dfn[u]){
		scc_cnt++;
		int x;
		do {
			x = stk[top--];
			id[x] = scc_cnt;
			instk[x] = false;
			scc_val_max[scc_cnt] = max(val[x], scc_val_max[scc_cnt]);
			scc_val_min[scc_cnt] = min(val[x], scc_val_min[scc_cnt]);		
		}while(x != u);
	}
}

void make(){
	
	for(int i = 1; i <= m; i++){
		if(id[u[i]] != id[v[i]]){
			edge[id[u[i]]].push_back(id[v[i]]);
			in[id[v[i]]]++;
		}
	}
}

void tp(){
	queue<int> q;
	q.push(id[1]);
	dp[id[1]] = max(dp[id[1]], scc_val_max[id[1]] - scc_val_min[id[1]]);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto i : edge[u]){
			in[i]--;
			scc_val_min[i] = min(scc_val_min[i], scc_val_min[u]);
			dp[i] = max(scc_val_max[i] - scc_val_min[i], max(dp[u], dp[i]));
			if(!in[i]){
				q.push(i);
			}
		}
	}
}

int main(){
	memset(scc_val_min, 127, sizeof(scc_val_min));
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}	
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> flag[i];
		if(flag[i] == 1){
			graph[u[i]].push_back(v[i]);
		} else {
			graph[u[i]].push_back(v[i]);
			graph[v[i]].push_back(u[i]);
		}
	}
	tarjan(1);
	make();
	tp();
	
	cout << dp[id[n]] << endl;
	return 0;
}
