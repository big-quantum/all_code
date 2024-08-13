#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2505;
int n, dist[MAXN][MAXN], m, k;
ll s[MAXN], ans;
bool arr[MAXN][MAXN];
vector<int> gra[MAXN], maxp[MAXN];
queue<int> q;

bool cmp(int a, int b) {
	return a > b;
}

void bfs(int u){
	dist[u][u] = 0;
	q.push(u);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(u != x){
			arr[u][x] = true;
			if(u != 1 && arr[1][x]){
				maxp[u].push_back(x);
				sort(maxp[u].begin(), maxp[u].end(), cmp);
				if(maxp[u].size() > 3) maxp[u].pop_back();
			}
		}
		if(dist[u][x] == k) continue;
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
	for(int i = 1; i <= n; i++){
		bfs(i);
	}
	for(int b = 2; b <= n; b++){
		for(int c = 2; c <= n; c++){
			if(b != c && arr[b][c]){
				for(auto a : maxp[b]){
					for(auto d : maxp[c]){
						if(a != c && b != d && a != d) ans = max(ans, s[a] + s[b] + s[c] + s[d]);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
