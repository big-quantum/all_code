#include<bits/stdc++.h>
using namespace std;
const int mod =  1e9 + 7;

int n, num[100005];
long long answer;
vector<int> mid;

int _next[200005], head[200005], to[200005], cnt;
void add(int u, int v){
	to[++cnt] = v;
	_next[cnt] = head[u];
	head[u] = cnt;
}

pair<long long, long long> dfs2(int root, int fa){
	pair<long long, long long> cntt, tmp;
	if(num[root] == 1){
		cntt.first++;
	}
	if(num[root] == -1){
		cntt.second++;
	}
	for(int i = head[root]; i != 0; i = _next[i]){
		int p = to[i];
		if(p != fa){
			tmp = dfs2(p, root);
			cntt.first += tmp.first;
			cntt.second += tmp.second;
			tmp.first = 0;
			tmp.second = 0;
		}
	}
	return cntt;
}

long long dfs1(int root){
	long long ans = 0;
	vector<pair<long long, long long>> sontree;
	for(int i = head[root]; i != 0; i = _next[i]){
		sontree.push_back(dfs2(to[i], root));
	}
	int m = sontree.size();
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			ans = (ans % mod + sontree[i].first * sontree[j].second % mod + sontree[i].second * sontree[j].first % mod) % mod;
		}
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		char tmp;
		cin >> tmp;
		if(tmp == 'C'){
			num[i] = 0;
			mid.push_back(i);
		}
		if(tmp == 'H') num[i] = -1;
		if(tmp == 'L') num[i] = 1;
	}
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	for(auto i : mid){
		answer = (answer + dfs1(i)) % mod;
	}
	cout << answer << endl;
	return 0;
}
