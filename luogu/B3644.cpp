#include<bits/stdc++.h>
using namespace std;

int n, in[105], to[105][105], cnt[105], ans[105], cntt;
bool vis[105];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		to[i][++cnt[i]] = x;
		while(x != 0){
			in[x]++;
			cin >> x;
			to[i][++cnt[i]] = x;
		}
		cnt[i]--;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!in[i]){
			q.push(i);
			vis[i] = true;
		}
	}
	while(!q.empty()){
		int p = q.front();
		ans[++cntt] = p;
		q.pop();
		for(int i = 1; i <= cnt[p]; i++){
			in[to[p][i]]--;
		}
		for(int i = 1; i <= n; i++){
			if(!in[i] && !vis[i]){
				q.push(i);
				vis[i] = true;
			}
		}
	}
	for(int i = 1; i <= cntt; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
