#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m, k, c[20], dp[20][135000], ans = INT_MAX;
vector<int> gra[N];
int dist[20][N];

void bfs(int p){
	for(int i = 1; i <= n; i++){
		dist[p][i] = INT_MAX / 2;
	}
	queue<int> q;
	q.push(c[p]);
	dist[p][c[p]] = 0;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(auto i : gra[f]){
			if(dist[p][i] == INT_MAX / 2){
				dist[p][i] = dist[p][f] + 1;
				q.push(i);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		gra[x].push_back(y);
		gra[y].push_back(x);
	} 
	cin >> k;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= k; i++){
		bfs(i);
		dp[i][1 << (i - 1)] = 1;
	}
	
	for(int i = 1; i < (1 << k); i++){
		for(int j = 1; j <= k; j++){
			if(i & (1 << (j - 1))){
				for(int l = 1; l <= k; l++){
					if(l != j && (i & (1 << (l - 1)))) dp[j][i] = min(dp[j][i], dp[l][i - (1 << (j - 1))] + dist[l][c[j]]);
				}
			}
		}
	}
	for(int i = 1; i <= k; i++){
		ans = min(ans, dp[i][(1 << k) - 1]);
	}
	if(ans >= 0x3f3f3f3f) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
