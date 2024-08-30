#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
#define ll long long

int c, t, n, m, k, d;
ll x[MAXN], y[MAXN], v[MAXN], dp[MAXN], tree[MAXN];
vector<pair<ll, ll>> com[MAXN];
vector<int> ls;

//树状数组 
int lowbit(ll x){
	return x&-x;
}

void update(ll k, ll x){
	k = n - k + 1;
	for(int pos = k; pos < MAXN; pos += lowbit(pos)){
		tree[pos] += x;
	}
}

ll query(int k){
	ll ans = 0;
	k = n - k + 1;
	for(int pos = k; pos; pos -= lowbit(pos)){
		ans += tree[pos];
	}
	return ans;
}

ll val(int from, int to){
//	ll ans = 0;
//	for(int i = 1; i <= m; i++){
//		if(x[i] - y[i] + 1 >= from && x[i] <= to) ans += v[i];
//	}
//	return ans;// 暴力搜索匹配 
	return query(from);//树状数组写法 
}

ll get(int x){
	
	if(x >= 0) return dp[x];
	else return 0;
}

void _init(){
	dp[0] = 0;
	ls.clear();
	for(int i = 1; i <= m + 5; i++){
		dp[i] = 0;
		tree[i] = 0;
		com[i].clear();
	}
}

int main(){
	//freopen("run2.in", "r", stdin);
	//freopen("run2.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; i++){
			cin >> x[i] >> y[i] >> v[i];
			ls.push_back(x[i]);
			ls.push_back(y[i]);
			//com[x[i]].push_back(make_pair(x[i] - y[i] + 1, v[i]));//按右端点记录 
		}
		sort(ls.begin(), ls.end());
		ls.erase(unique(ls.begin(), ls.end()), ls.end());//去重并排序 
		for(int i = 1; i <= m; i++){
			x[i] = lower_bound(ls.begin(), ls.end(), x[i]) - ls.begin() + 1;
			y[i] = lower_bound(ls.begin(), ls.end(), y[i]) - ls.begin() + 1;
			com[x[i]].push_back(make_pair(x[i] - y[i] + 1, v[i]));//按右端点记录 
		}
		for(int i = 1; i <= m; i++){
			for(auto j : com[i]){//添加树状数组 
				update(j.first, j.second);
			}
			//for(int j = max(i - k + 1, 1); j <= i; j++){//暴力检索
			for(int j = i; j >= 1 && ls[i] - ls[j] + 1 <= k; j--){ 
				//验证j - 1位是不是与第j位相邻
				//离散化后j - 1位不一定就是原来的第j - 1天 
				int pos = j - 2;
				if(ls[j - 1] != ls[j] - 1) pos = j - 1;
				dp[i] = max(dp[i], get(pos) - (ls[i] - ls[j] + 1) * d + val(j, i));
			}
			dp[i] = max(dp[i - 1], dp[i]);
		}
//		for(int i = 1; i <= n; i++){
//			cout << dp[i] << endl; 
//		}
		cout << dp[m] << endl;
		_init();
	}
	
	
	return 0;
}
