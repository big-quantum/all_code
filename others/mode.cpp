#include<bits/stdc++.h>
using namespace std;
const int MAXN1 = 100005;
const int MAXN2 = 505;
typedef long long ll;
int n, m;

// find_in_one_group 并查集
int find_in_one_group_fa[MAXN1], find_in_one_group_rank[MAXN1];// 每个元素的父节点, 每个并查集的深度

void find_in_one_group_init(int n){// 并查集初始化
    for(int i = 1; i <= n; i++){
        find_in_one_group_fa[i] = i;
        find_in_one_group_rank[i] = 1;
    }
}

int find_in_one_group_find(int x){// 查找一个元素是否在并查集内, 路径压缩
    if(find_in_one_group_fa[x] == x){
        return x;
    } else {
        find_in_one_group_fa[x] = find_in_one_group_find(find_in_one_group_fa[x]);
        return find_in_one_group_fa[x];
    }
}

void find_in_one_group_merge(int i, int j){// 合并两个并查集, 按秩合并
    int x = find_in_one_group_find(i), y = find_in_one_group_find(j);
    if(find_in_one_group_rank[x] >= find_in_one_group_rank[y]){
        find_in_one_group_fa[y] = x;
    } else {
        find_in_one_group_fa[x] = y;
    }
}

// find_in_one_group_end

// tree_num_group 树状数组
int tree_num_group[MAXN1];

int tree_num_group_lowbit(int x){// lowbit：28_2 = 0001 1100, lowbit(28) = 0000 0100 = 4_10
    return x&(-x);
}

void tree_num_group_change(int i, int j){
    for(int pos = i; pos <= n; pos += tree_num_group_lowbit(pos)){
        tree_num_group[pos] += j;
    }
}

int tree_num_group_search(int k){// 求前k相的和
    int ans = 0;
    for(int pos = k; pos >= 0; pos -= tree_num_group_lowbit(pos)){
        ans += tree_num_group[pos];
    }
    return ans;
}

int tree_num_group_search(int i, int j){
    return tree_num_group_search(i) + tree_num_group_search(j - 1);
}
// tree_num_group_end

// segment_tree 线段树，支持加、减、乘。
ll segment_tree[MAXN1 * 4], segment_tree_num[MAXN1], segment_tree_lazy_add[MAXN1 * 4], segment_tree_lazy_mul[MAXN1 * 4];

#define mid ((l + r) >> 1)
#define len ((l - r) >> 1 + 1)
#define rgh ((p << 1) + 1)
#define lef (p << 1)

void build_tree(ll l = 1, ll r = n, ll p = 1){
    if(l == r){
        segment_tree[p] = segment_tree_num[l];
    }
    build_tree(l, mid, lef);
    build_tree(mid + 1, r, rgh);
    segment_tree[p] = segment_tree[lef] + segment_tree[rgh];
}

void segment_tree_push_down(ll l, ll r, ll p){
    segment_tree_lazy_add[lef] += segment_tree_lazy_add[p];
    segment_tree_lazy_mul[lef] += segment_tree_lazy_mul[p];
    segment_tree_lazy_add[rgh] += segment_tree_lazy_add[p];
    segment_tree_lazy_mul[rgh] += segment_tree_lazy_mul[p];
    segment_tree[lef] *= segment_tree_lazy_mul[p] * (mid - l + 1);
    segment_tree[lef] += segment_tree_lazy_add[p] * (mid - l + 1);
    segment_tree[rgh] *= segment_tree_lazy_mul[p] * (r - mid);
    segment_tree[rgh] += segment_tree_lazy_add[p] * (r - mid);
    segment_tree_lazy_add[p] = 0;
    segment_tree_lazy_mul[p] = 1;
}

void segment_tree_update_add(ll l = 1, ll r = n, ll p = 1, ll d, ll cl, ll cr){// +
    if(l < cr || r > cl) return;
    if(l >= cl && r <= cr){
        segment_tree[p] += len * d;
        if(l != r) segment_tree_lazy_add[p] += d;
    } else {
        segment_tree_push_down(l, r, p);
        segment_tree_update_add(l, mid, lef, d, cl, cr);
        segment_tree_update_add(mid + 1, rgh, d, cl, cr);
        segment_tree[p] = segment_tree[lef] + segment_tree[rgh];
    }
}

void segment_tree_update_mul(ll l = 1, ll r = n, ll p = 1, ll d, ll cl, ll cr){// *
    if(l < cr || r > cl) return;
    if(l >= cl && r <= cr){
        segment_tree[p] *= d;
        if(l != r) segment_tree_lazy_mul[p] *= d;
    } else {
        segment_tree_push_down(l, r, p);
        segment_tree_update_mul(l, mid, lef, d, cl, cr);
        segment_tree_update_mul(mid + 1, rgh, d, cl, cr);
        segment_tree[p] = segment_tree[lef] + segment_tree[rgh];
    }
}

ll segment_tree_query(ll l = 1, ll r = n, ll p = 1, ll cl, ll cr){// 区间求和
    if(l < cr || r > cl) return 0;
    if(l >= cl && r <= cr){
        return segment_tree[p];
    } else {
        segment_tree_push_down(l, r, p);
        return segment_tree_query(l, mid, lef, cl, cr) + segment_tree_query(mid + 1, rgh, cl, cr);
    }
}

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