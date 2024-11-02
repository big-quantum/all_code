#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2505;
int n, dist[MAXN][MAXN], m, k, maxp[MAXN][3];
ll s[MAXN], ans;
vector<int> gra[MAXN];
queue<int> q;

void check(int a, int b, int c, int d){
	if(a == 0 || d == 0) return;
	if(a == b || a == c || a == d || b == c || b == d || c == d) return;
	if(dist[1][a] > k || dist[a][b] > k || dist[b][c] > k || dist[c][d] > k || dist[d][1] > k) return;
	ans = max(ans, s[a] + s[b] + s[c] + s[d]);
}

void bfs(int u){
	dist[u][u] = 0;
	q.push(u);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto v : gra[x]){
			if(dist[u][v] == -1) dist[u][v] = dist[u][x] + 1, q.push(v);
		}
	}
}

int main(){
	memset(dist, -1, sizeof(dist));
	cin >> n >> m >> k;
	k += 1;
	for(int i = 2; i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= m; i++){
		int x, y; 
		cin >> x >> y;
		gra[x].push_back(y);
		gra[y].push_back(x);
	}
	bfs(1);
	for(int i = 2; i <= n; i++){
		bfs(i);
		for(int j = 2; j <= n; j++){
			if(dist[i][j] != -1 && dist[1][j] != -1 && dist[i][j] <= k && dist[1][j] <= k && i != j){
				int pos = j; 
				if(s[pos] > s[maxp[i][0]]) swap(pos, maxp[i][0]);
				if(s[pos] > s[maxp[i][1]]) swap(pos, maxp[i][1]);
				if(s[pos] > s[maxp[i][2]]) swap(pos, maxp[i][2]);
			}
		}
	}
	for(int b = 2; b <= n; b++){
		for(int c = 2; c <= n; c++){
			if(b != c && dist[b][c] <= k && dist[b][c] != -1){
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						check(maxp[b][i], b, c, maxp[c][j]);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
