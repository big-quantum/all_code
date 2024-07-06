#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int n, m, dep[MAXN], fa[MAXN], hson[MAXN], sz[MAXN], top[MAXN];
vector<int> tree[MAXN];

void dfs1(int p, int depp = 1){
    int size = 1, maxtree = 0;
    dep[p] = depp;
    for(auto q : tree[p]){
        if(!dep[q]){
            
            fa[q] = p;
            dfs1(q, depp + 1);
            size += sz[q];
            if(sz[q] > maxtree) {
                maxtree = sz[q];
                hson[p] = q;
            }
        }
    }
    sz[p] = size;
}

void dfs2(int p){
    for(auto q : tree[p]){
        if(!top[q]){
            if(q == hson[p]){
                top[q] = top[p];
            } else {
                top[q] = q;
            }
            dfs2(q);
        }
    }
}

int lca(int a, int b){
    while(top[a] != top[b]){
        if(dep[top[a]] > dep[top[b]]){
            a = fa[top[a]];
        } else {
            b = fa[top[b]];
        }
    }
    return (dep[a] > dep[b] ? b : a);
}
/*
int n, m, dep[MAXN], fa[MAXN][205], log_2[MAXN], p[MAXN];
bool vis[MAXN * 2];
int st[MAXN];
int head[MAXN * 2], to[MAXN * 2], nextt[MAXN * 2], cnt, ans[MAXN];
vector<pair<int, int>> query[MAXN];*/
/*
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
*/
/*
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
*/

int main(){
    int s;
    cin >> n >> m >> s;

    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs1(s);
    top[s] = s;
    dfs2(s);

    while (m--){
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    
    /*
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
    }*/
    return 0;
}