#include<bits/stdc++.h>
using namespace std;
const int MAXN1 = 100005;
const int MAXN2 = 505;
const int mod =  1e9 + 7;
typedef long long ll;
int n, m;

// union_find 并查集
int uf_fa[MAXN1], uf_rank[MAXN1];// 每个元素的父节点, 每个并查集的深度

void uf_init(int n){// 并查集初始化
    for(int i = 1; i <= n; i++){
        uf_fa[i] = i;
        uf_rank[i] = 1;
    }
}

int uf_find(int x){// 查找一个元素是否在并查集内, 路径压缩
    if(uf_fa[x] == x){
        return x;
    } else {
        uf_fa[x] = uf_find(uf_fa[x]);
        return uf_fa[x];
    }
}

void uf_merge(int i, int j){// 合并两个并查集, 按秩合并
    int x = uf_find(i), y = uf_find(j);
    if(uf_rank[x] >= uf_rank[y]){
        uf_fa[y] = x;
    } else {
        uf_fa[x] = y;
    }
}

// union_find-end

// tree_num_group 树状数组
int tree_ng[MAXN1];

int tree_ng_lowbit(int x){// lowbit：28_2 = 0001 1100, lowbit(28) = 0000 0100 = 4_10
    return x&(-x);
}

void tree_ng_change(int i, int j){
    for(int pos = i; pos <= n; pos += tree_ng_lowbit(pos)){
        tree_ng[pos] += j;
    }
}

int tree_ng_search(int k){// 求前k相的和
    int ans = 0;
    for(int pos = k; pos >= 0; pos -= tree_ng_lowbit(pos)){
        ans += tree_ng[pos];
    }
    return ans;
}

int tree_ng_search(int i, int j){
    return tree_ng_search(i) + tree_ng_search(j - 1);
}
// tree_num_group_end

// segment_tree 线段树，支持加、减、乘。
ll seg_tree[MAXN1 * 4], seg_num[MAXN1], seg_lazy_add[MAXN1 * 4], seg_lazy_mul[MAXN1 * 4];

#define mid ((l + r) >> 1)
#define rgh ((p << 1) + 1)
#define lef (p << 1)

void build_tree(ll l, ll r, ll p){
    seg_lazy_add[p] = 0;
    seg_lazy_mul[p] = 1;
    if(l == r){
        seg_tree[p] = seg_num[l] % mod;
        return;
    }
    build_tree(l, mid, lef);
    build_tree(mid + 1, r, rgh);
    seg_tree[p] = (seg_tree[lef] + seg_tree[rgh]) % mod;
}

void seg_push_down(ll l, ll r, ll p){
    seg_lazy_add[lef] = (seg_lazy_add[p] + seg_lazy_mul[p] * seg_lazy_add[lef]) % mod;
    seg_lazy_mul[lef] = (seg_lazy_mul[lef] * seg_lazy_mul[p]) % mod;
    seg_lazy_add[rgh] = (seg_lazy_add[p] + seg_lazy_mul[p] * seg_lazy_add[rgh]) % mod;
    seg_lazy_mul[rgh] = (seg_lazy_mul[rgh] * seg_lazy_mul[p]) % mod;
    seg_tree[lef] = (seg_tree[lef] * seg_lazy_mul[p] + seg_lazy_add[p] * (mid - l + 1)) % mod;
    seg_tree[rgh] = (seg_tree[rgh] * seg_lazy_mul[p] + seg_lazy_add[p] * (r - mid)) % mod;
    seg_lazy_add[p] = 0;
    seg_lazy_mul[p] = 1;
}

void seg_update_add(ll d, ll cl, ll cr, ll l, ll r, ll p){// +
    if(l > cr || r < cl) return;
    if(l >= cl && r <= cr){
        seg_tree[p] = (seg_tree[p] + (r - l + 1) * d) % mod;
        if(l != r) seg_lazy_add[p] = (seg_lazy_add[p] + d) % mod;
    } else {
        seg_push_down(l, r, p);
        seg_update_add(d, cl, cr, l, mid, lef);
        seg_update_add(d, cl, cr, mid + 1, r, rgh);
        seg_tree[p] = (seg_tree[lef] + seg_tree[rgh]) % mod;
    }
}

void seg_update_mul(ll d, ll cl, ll cr, ll l, ll r, ll p){// *
    if(l > cr || r < cl) return;
    if(l >= cl && r <= cr){
        seg_tree[p] = (seg_tree[p] * d) % mod;
        if(l != r){
            seg_lazy_mul[p] = (seg_lazy_mul[p] * d) % mod;
            seg_lazy_add[p] = (seg_lazy_add[p] * d) % mod;
        }
    } else {
        seg_push_down(l, r, p);
        seg_update_mul(d, cl, cr, l, mid, lef);
        seg_update_mul(d, cl, cr, mid + 1, r, rgh);
        seg_tree[p] = (seg_tree[lef] + seg_tree[rgh]) % mod;
    }
}

ll seg_query(ll cl, ll cr, ll l = 1, ll r = n, ll p = 1){// 区间求和
    if(l > cr || r < cl) return 0;
    if(l >= cl && r <= cr){
        return seg_tree[p];
    } else {
        seg_push_down(l, r, p);
        return (seg_query(cl, cr, l, mid, lef) + seg_query(cl, cr, mid + 1, r, rgh)) % mod;
    }
}

#undef lef
#undef rgh
#undef mid

// segment_tree_end

// sq_

// lca_

const int MAXN = 500005;
int n, m, dep[MAXN], fa[MAXN][205], log_2[MAXN], p[MAXN];
bool vis[MAXN * 2];
int st[MAXN];
int head[MAXN * 2], to[MAXN * 2], nextt[MAXN * 2], cnt, ans[MAXN];
vector<pair<int, int>> query[MAXN];

void add(int a, int b){
    to[++cnt] = b;
    nextt[cnt] = head[a];
    head[a] = cnt;
    to[++cnt] = a;
    nextt[cnt] = head[b];
    head[b] = cnt;
}

int find(int x){
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}

void tarjan(int u){
    st[u] = 1;
    for (int i = head[u]; i != 0; i = nextt[i]){
        int t = to[i];
        if(!st[t]) {
            tarjan(t);
            p[t] = u;
        }
    }
    pair<int, int> tmp;
    for(auto tmp : query[u]){
        if(st[tmp.first] == 2){
            ans[tmp.second] = find(tmp.first);
        }
    }
    st[u] = 2;
}


void dfs(int s, int fath = 0){
    if(vis[s]) return;
    vis[s] = true;
    dep[s] = dep[fath] + 1;
    fa[s][0] = fath;
    for(int i = 1; i <= log_2[dep[s]]; i++){
        fa[s][i] = fa[fa[s][i - 1]][i - 1];
    }
    for(int id = head[s]; id != 0; id = nextt[id]){
        dfs(to[id], s);
    }
}

int lca(int a, int b){
    if(dep[a] > dep[b]) swap(a, b);
    for(int i = log_2[dep[b] - dep[a]]; i >= 0; i--){
        if(dep[fa[b][i]] >= dep[a]){
            b = fa[b][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = log_2[dep[a]]; i >= 0; i--){
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}


int main(){
    int s;
    cin >> n >> m >> s;
    for(int i = 1; i <= n - 1; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    // for(int i = 1; i <= n; i++){
    //     log_2[i] = log_2[i / 2] + 1;
    // }
    // dfs(s);
    int count = 1;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(a == b){
            ans[count] = a;
        } else {
            query[a].push_back({b, count});
            query[b].push_back({a, count});
        }
        count++;
        //cout << lca(a, b) << endl;
    }
    for(int i = 1; i <= n; i++){
        p[i] = i, st[i] = 0;
    }
    tarjan(s);

    for(int i = 1; i <= m; i++){
        cout << ans[i] << endl;
    }
    return 0;
}

int main(){

    return 0;
}
//负环

int t, n, m;

struct edge{
	int w, to, next; 
}e[30005];

int head[3005], cnt;

void add(int from, int to, int w){
	e[++cnt].w = w;
	e[cnt].to = to;
	e[cnt].next = head[from];
	head[from] = cnt;	
}

int dis[3005], cntt[3005];
bool flag[3005];

bool spfa(){
	memset(dis, 0x3f, sizeof(dis));
	memset(cntt, 0, sizeof(cntt));
	memset(flag, false, sizeof(flag));
	
	queue<int> q;
	q.push(1);
	flag[1] = true;
	dis[1] = 0;

	while(!q.empty()){
		int f = q.front();
		q.pop();
		flag[f] = false;
		for(int i = head[f]; i != -1; i = e[i].next){
			int to = e[i].to;
			if(dis[to] > dis[f] + e[i].w){
				dis[to] = dis[f] + e[i].w;
				cntt[to] = cntt[f] + 1;
				if(cntt[to] >= n) return true;
				if(!flag[to]){
					q.push(to);
					flag[to] = true;
				}
			}
		}
	}
	
	return false;

}

int main(){
	cin >> t;
	
	while(t--){
		
		memset(head, -1, sizeof(head));
		cnt = 0;

		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			int u, v, w;
			scanf("%d%d%d",&u,&v,&w);
			if(w >= 0){
				add(u, v, w);
				add(v, u, w);
			} else {
				add(u, v, w);
			}
		}
		
		for(int i = 1; i <= m*2; i++){
			cout<<e[i].next<<" "<<e[i].to<<" "<<e[i].w<<endl;;
		}
		if(spfa()) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	
	return 0;
}

//quickpower
long long a, b, p, ans = 1, bb;

int main(){
	
	cin >> a >> b >> p;
	bb = b;
	long long pow = a;
	while(b > 0){
		if(b & 1){
			ans *= pow;
			ans %= p;
		}
		pow *= pow;
		pow %= p;
		b >>= 1; 
	}
	ans %= p;
	printf("%lld^%lld mod %lld=%lld", a, bb, p, ans);
	return 0;
}

//单调栈
int n, length[3000005], ans[3000005];
stack<int> sta;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &length[i]);
    }
    for (int i = 1; i <= n; i++) {
        while(!sta.empty() && length[i] > length[sta.top()]){
            ans[sta.top()] = i;
            sta.pop();
        }
        sta.push(i);
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
//差分约束
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

//单调队列、滑动窗口
deque<pair<int, int> > q1, q2;//q1减，q2增 
int n, a[1000005], k, ans[1000005], cnt = 1;

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		pair<int, int> tmp;
		tmp.first = a[i];
		tmp.second = i;
		while(!q1.empty() && a[i] >= q1.back().first) q1.pop_back();
		while(!q2.empty() && a[i] <= q2.back().first) q2.pop_back();
		q1.push_back(tmp);
		q2.push_back(tmp);
		while(i - k >= q1.front().second) q1.pop_front();
		while(i - k >= q2.front().second) q2.pop_front();
		if(i >= k){
			cout << q2.front().first << " ";
			ans[cnt++] = q1.front().first;
		}
	}
	cout << endl;
	for(int i = 1; i < cnt; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

//diction_tree

const int MAXN = 3000005;

int cnt = 1, tt, cntt[MAXN], _next[MAXN][100];

void insert(string s){
    int cur = 1;
    for(auto c : s){
        if(!_next[cur][c - '0']){
            _next[cur][c - '0']= ++cnt;
        }
        cur = _next[cur][c - '0'];
        cntt[cur]++;
    }
}

int find(string s){
    int cur = 1;
    for(auto c : s){
        if(!_next[cur][c - '0']) return 0;
        cur = _next[cur][c - '0'];
    }
    return cntt[cur];
}

int main(){
    scanf("%d", &tt);
    while(tt--){
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i = 0; i <= cnt; i++)
            for(int j = 0; j < 100; j++)
                _next[i][j] = 0;
        for(int i = 0; i <= cnt; i++)
            cntt[i] = 0;
        cnt = 1
        string a;
        for(int i = 1; i <= n; i++){
            cin >> a;
            insert(a);
        }
        for(int i = 1; i <= q; i++){
            cin >> a;
            cout << find(a) << endl;
        }
    }
    return 0;
}
//欧拉筛
//2-n中的质数 O(n) P3383
void prime(int n){
    bool is_prime[n + 2];
    memset(is_prime, true, sizeof(is_prime));
    vector<int> prime;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]) prime.push_back(i);
        for(int p : prime){
            if(i * p > n) break;
            is_prime[i * p] = false;
            if(i % p == 0) break;
        }
    }
    for(int p : prime){
        cout << p << " ";
    }
}
