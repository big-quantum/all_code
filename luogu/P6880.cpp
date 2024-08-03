#include<bits/stdc++.h>
using namespace std;

long long gra[205][205], n, m, u[50005], v[50005], w[50005], d[50005], gra_sc[205][205], ans = INT_MAX;
//gra[u][v][0] -> 最小值  gra[u][v][1] -> 最小值 
long long dis_1[205], dis_n[205], disf_1[205], disf_n[205], fa_1[205], fa_n[205], faf_1[205], faf_n[205], dist[205], fa[205];
bool vis[205];

void dij(int s, long long *dis, long long *fa){
	for(int i = 0; i <= n; i++){
		dis[i] = LLONG_MAX;
		vis[i] = false;
	}
	dis[s] = 0;
	int u = 0;
	do {
		u = 0;
		for(int i = 1; i <= n; i++){
			if(!vis[i] && dis[i] < dis[u]) u = i;
		}
		vis[u] = true;
		for(int v = 1; v <= n; v++){
			if(!vis[v] && dis[u] + gra[u][v] < dis[v]){
				dis[v] = dis[u] + gra[u][v];
				fa[v] = u; 
			}
		}
	} while(u != 0);
	
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			gra[i][j] = INT_MAX;
			gra_sc[i][j] = INT_MAX;
		}
	}
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i] >> d[i];
		if(gra[u[i]][v[i]] >= w[i]){
			gra_sc[u[i]][v[i]] = gra[u[i]][v[i]];
			gra[u[i]][v[i]] = w[i];
		} else gra_sc[u[i]][v[i]] = min(gra_sc[u[i]][v[i]], w[i]);
	}
	
	dij(1, dis_1, fa_1);
	dij(n, dis_n, fa_n);
	//反图 
	int gra_tmp[205][205];
	for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				gra_tmp[i][j] = gra[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				gra[i][j] = gra_tmp[j][i];
		}
	}
	dij(1, disf_1, faf_1);
	dij(n, disf_n, faf_n);
	//还原 
	for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				gra[i][j] = gra_tmp[i][j];
		}
	}
	ans = min(dis_1[n] + dis_n[1], ans);
	// 枚举 
	for(int i = 1; i <= m; i++){
		long long tmp1 = gra[u[i]][v[i]], tmp2 = gra[v[i]][u[i]], tmp = d[i];
		//翻转 
		gra[u[i]][v[i]] = gra_sc[u[i]][v[i]];
		gra[v[i]][u[i]] = min(w[i], gra[v[i]][u[i]]);
		//1`n
		if(fa_1[v[i]] != u[i] || dis_1[u[i]] + w[i] != dis_1[v[i]]){
			tmp += min(dis_1[n], dis_1[v[i]] + w[i] + disf_n[u[i]]);
		} else {
			dij(1, dist, fa);
			tmp += dist[n];
		}
		//n`1
		if(fa_n[v[i]] != u[i] || dis_n[u[i]] + w[i] != dis_n[v[i]]){
			tmp += min(dis_n[1], dis_n[v[i]] + w[i] + disf_1[u[i]]);
		} else {
			dij(n, dist, fa);
			tmp += dist[1];
		}
		//还原 
		gra[u[i]][v[i]] = tmp1;
		gra[v[i]][u[i]] = tmp2;
		ans = min(ans, tmp);
	} 
	if(ans != INT_MAX) cout << ans << endl; 
	else cout << -1 << endl; 
	return 0;
}