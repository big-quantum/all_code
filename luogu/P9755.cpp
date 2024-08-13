#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;

int n, b[N], c[N], fa[N], t[N], stk[N];
long long a[N];
vector<int> gra[N];
int p[N];
bool vis[N];

inline __int128 height(__int128 l, __int128 r, int i){
	if(c[i] >= 0) return (r - l + 1) * b[i] + (r - l + 1) * (l + r) / 2 * c[i];
	__int128 x = (1 - b[i]) / c[i];
	if(x < l){
		return r - l + 1;
	}
	if(x > r){
		return (r - l + 1) * b[i] + (r - l + 1) * (l + r) / 2 * c[i];
	}
	return b[i] * (x - l + 1) + (x - l + 1) * (l + x) / 2 * c[i] + r - x;
}

inline bool cmp(int a, int b){
	return t[a] < t[b];
}

inline void dfs(int p, int f){
	fa[p] = f;
	for(auto i : gra[p]){
		if(i != f) dfs(i, p);
	}
}

inline bool check(int x){
	for(int i = 1; i <= n; i++){
		if(height(1, x, i) < a[i]) return false;
		int dl = 1, dr = n, mid;
		while(dl <= dr){
			mid = (dl + dr + 1) >> 1;
			if(height(mid, x, i) >= a[i]) dl = mid + 1;
			else dr = mid - 1;
		}
		t[i] = mid;
		vis[i] = false;
		p[i] = i;
	}
	sort(p + 1, p + n + 1, cmp);
	int tim = 0, top = 0;
	for(int i = 1; i <= n ; i ++){
		int now = p[i];
		//stack<int> stk;
		while(!vis[now]){
			//stk.push(now);
			stk[++top] = now;
			vis[now] = true;
			now = fa[now];
		}
		while(top){
			if(t[stk[top--]] < ++tim) return false;
			//else stk.pop();
		}
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld%d%d", &a[i], &b[i], &c[i]);
	}
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		gra[u].push_back(v);
		gra[v].push_back(u);
	}
	dfs(1, 0);
	vis[0] = true;
	int l = n, r = 1e9, mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
