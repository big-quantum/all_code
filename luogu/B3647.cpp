#include<bits/stdc++.h>
using namespace std;

int n, m, mapp[105][105];

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			mapp[i][j] = INT_MAX;
			if(i == j) mapp[i][j] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	
	init();
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		mapp[u][v] = min(w, mapp[u][v]);
		mapp[v][u] = min(w, mapp[v][u]);
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(mapp[i][k] != INT_MAX && mapp[k][j] != INT_MAX)
				mapp[i][j] = min(mapp[i][k] + mapp[k][j], mapp[i][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << mapp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
