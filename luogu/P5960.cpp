#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

int _next[MAXN], head[MAXN], to[MAXN], cnt, val[MAXN];
int n, m;

void add(int u, int v, int w){
	to[++cnt] = v;
	val[cnt] = w;
	_next[cnt] = head[u];
	head[u] = cnt;
}

int dist[MAXN], cmt[MAXN];
bool inque[MAXN];
queue<int> q;
bool spfa(int from){
	inque[from] = true;
	q.push(from);
	for(int i = 1; i <= n; i++){
		dist[i] = INT_MAX;
	}
	dist[from] = 0;
	
	while(!q.empty()){
		int p = q.front();
		inque[p] = false;
		q.pop();
		if(cmt[p] > n) return false;
		for(int i = head[p]; i != 0; i = _next[i]){
			int tt = to[i];
			if(dist[tt] > dist[p] + val[i]){
				dist[tt] = dist[p] + val[i];
				if(!inque[tt]){
					inque[tt] = true;
					q.push(tt);
					cmt[tt]++;
				}
			}
		}
	}
	return true;
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		add(x2, x1, y);
	}
	for(int i = 1; i <= n; i++){
		add(n + 1, i, 0);
	}
	
	if(spfa(n + 1)){
		for(int i = 1; i <= n; i++){
			cout << dist[i] << " ";
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
