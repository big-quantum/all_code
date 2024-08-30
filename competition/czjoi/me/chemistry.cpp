#include<bits/stdc++.h>
using namespace std;
const int mod =  1e9 + 7;

int n, dep[100005];
int ans[1205];

int _next[200005], head[200005], to[200005], cnt, fa[200005][20];
int Log2[100005];

bool vis[100005];
void dfs(int root, int f){
	if(vis[root]) return;
	vis[root] = true;
	dep[root] = dep[f] + 1;
	fa[root][0] = f;
	for(int i = 1; i <= Log2[dep[root]]; i++){
		fa[root][i] = fa[fa[root][i - 1]][i - 1];
	}
	for(int i = head[root]; i != 0; i = _next[i]){
		int p = to[i];
		if(p != f){
			dfs(p, root);
		}
	}
}

void add(int u, int v){
	to[++cnt] = v;
	_next[cnt] = head[u];
	head[u] = cnt;
}

int lca(int a, int b){
	if(dep[a] > dep[b]) swap(a, b);
	while(dep[a] != dep[b]){
		b = fa[b][Log2[dep[b] - dep[a]]];
	}
	if(a == b) return a;
	for(int k = Log2[dep[a]]; k >= 0; k--){
		if(fa[a][k] != fa[b][k]){
			a = fa[a][k];
			b = fa[b][k];
		}
	}
	return fa[a][0];
}

int main(){
	cin >> n;
	for(int i = 2; i <= n; i++){
		int t;
		cin >> t;
		add(i, t);
		add(t, i);
	}
	for(int i = 2; i <= n; i++){
		Log2[i] = Log2[i / 2] + 1;
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int l = lca(i, j);
			ans[(dep[l] - dep[i] + 1)^(dep[l] - dep[j] + 1
			)]++;
		}
	}
	int cntt = 0;
	while(ans[cntt] != 0){
		cout << ans[cntt++] << endl;
	}
	return 0;
}
