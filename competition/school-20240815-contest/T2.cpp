#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;

int n, m, cnt, cntt = 1;
pair<int, int> edge[MAXN];
int _next[MAXN], head[MAXN], to[MAXN];
vector<int> tree[100005];
int dfn[MAXN], low[MAXN], times;
int stk[MAXN], top;
int id[MAXN], dcc_cnt;
bool is_bridge[MAXN];
int log_2[MAXN], dep[MAXN], fa[MAXN][30], sen[30];
bool vis[MAXN];

void add(int u, int v){
    to[cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt++;
}

void tarjan(int u, int f){
    dfn[u] = ++times;
    low[u] = times;
    stk[++top] = u;
    vis[u] = true;
    for(int i = head[u]; i != -1; i = _next[i]){
        int j = to[i];
        if(j == f) continue;
        if(!dfn[j]){
            tarjan(j, u);
            low[u] = min(low[u], low[j]);
        } else if(vis[u]){
            low[u] = min(low[u], dfn[j]);
        }
    }
    if(dfn[u] == low[u]){
        ++dcc_cnt;
        int tmp;
        do {
            tmp = stk[top--];
            id[tmp] = dcc_cnt;
            vis[tmp] = false;
        } while (tmp != u);
    }
}

void init(){
    for(int i = 2; i <= MAXN; i++){
        log_2[i] = log_2[i / 2] + 1;
    }
    for(int i = 1; i <= m; i++){
        int a = id[edge[i].first], b = id[edge[i].second];
        if(a != b){
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
}

void dfs(int p, int f){
    fa[p][0] = f;
    dep[p] = dep[f] + 1;
    for(int i = 1; (1 << i) <= dep[p]; i++){
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    }
    for(auto i : tree[p]){
        if(i != f) dfs(i, p);
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
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        edge[i] = make_pair(x, y);
        add(x, y);
        add(y, x);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i, -1);
    }
    init();
    dfs(1, 0);
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        cout << dep[id[a]] + dep[id[b]] - 2 * dep[lca(id[a], id[b])] << endl;
    }

    return 0;
}
