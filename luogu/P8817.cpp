#include<bits/stdc++.h>
using namespace std;

struct node{
	int id, step;
};

int n, m, k;
long long ans;
bool gra[2505][2505];
bool arv[2505][2505];
vector<int> mid1[2505], mid2[2505];
int val[2505];

void dfs_path(){
	for(int i = 1; i <= n; i++){
		queue<node> que;
		node tmp;
		tmp.id = i;
		tmp.step = -1;
		que.push(tmp);
		for(int j = 1; j <= n; j++) {
			int fr = que.front().id, step = que.front().step;
			que.pop();
			if(step > k || j == i) continue;
			if(gra[fr][j]) {
				node tmpp;
				tmpp.id = j;
				tmpp.step = step + 1;
				que.push(tmpp);
				arv[i][j] = true;
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		gra[x][y] = true;
		gra[y][x] = true;
	}

	dfs_path();

	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= n; j++) {
			if(arv[1][i] && arv[i][j]) mid1[j].push_back(val[i]);
            if(arv[n][i] && arv[i][j]) mid2[j].push_back(val[i]);
		}
	}

	for(int f2 = 2; f2 <= n; f2++){
		for(int f3 = 2; f3 <= n; f3++){
            for(auto i : mid1[f2]) {
                for(auto j : mid2[f3]) {
                    if(f2 != i && f3 != j && f2 != j){
                        ans = max(ans, (long long)(val[i] + val[f2] + val[f3] + val[j]));
                    }
                }
            }
		}
	}

    cout << ans << endl;

	return 0;
}