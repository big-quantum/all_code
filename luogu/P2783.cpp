#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, m, head[MAXN], _next[MAXN], to[MAXN], cnt = 1;
vector<pair<int, int>> is_bridge;

void add(int u, int v){
    to[cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt++;
}

int dfn[MAXN], low[MAXN], times, stk[MAXN], top, id[MAXN], dcc_cnt;
bool vis[MAXN];
void tarjan(int u, int f){
    dfn[u] = low[u] = ++times;
    vis[u] = true;
    stk[++top] = u; 
    for(int i = head[u]; i != -1; i = _next[i]){
        int j = to[i];
        if(j == f) continue;
        if(!dfn[j]){
            tarjan(j, u);
            low[u] = min(low[u], low[j]);
            if(low[j] > dfn[u]){
                is_bridge.emplace_back(j, u);
            }
        } else {
            if(vis[u]) low[u] = min(low[u], dfn[j]);
        }
    }
    if(dfn[u] == low[u]){
        dcc_cnt++;
        int tmp;
        do{
            tmp = stk[top--];
            id[tmp] = dcc_cnt;
            vis[tmp] = false;
        } while (tmp != u);
    }
}

int log_2[MAXN];
vector<int> tree[MAXN];
void init(){
    for(int i = 2; i <= n; i++){
        log_2[i] = log_2[i / 2] + 1;
    }
    for(auto i : is_bridge){
        int a = id[i.first];
        int b = id[i.second];
        if(a != b){
            tree[a].push_back(b);
            tree[b].push_back(a);
        } 
    }
}

int fa[MAXN][30], dep[MAXN];
void dfs(int u, int f){
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for(int i = 1; i <= log_2[dep[u]]; i++){
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for(auto i : tree[u]){
        if(i != f) dfs(i, u);
    }
}

int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = log_2[dep[a] - dep[b]]; i >= 0; i--){
        if(dep[fa[a][i]] >= dep[b]){
            a = fa[a][i];
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
        add(x, y);
        add(y, x);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i, -1);
    }
    init();
    dfs(1, 0);
    int tot;
    cin >> tot;
    while(tot--){
        int x, y;
        scanf("%d%d" , &x , &y);
        x = id[x];
        y = id[y];
        int ans = dep[x] + dep[y] - 2 * dep[lca(x, y)] + 1;
        vector<bool> p;
        while(ans != 0){
            p.push_back(ans & 1);
            ans >>= 1;
        }
        for(int i = p.size() - 1; i >= 0; i--){
            cout << p[i];
        }
        cout << endl;
    }
    return 0;
}