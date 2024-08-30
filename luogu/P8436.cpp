#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;

int n, m, cnt = 2;
vector<pair<int, int>> gra[MAXN];
vector<int> ans[MAXN];
bool is_bridge[MAXN * 2], instk[MAXN];
int dfn[MAXN], low[MAXN], times, stk[MAXN], top, dcc_cnt;

void tarjan(int u, int f){
    dfn[u] = low[u] = ++times;
    for(auto i : gra[u]){
        if(!dfn[i.first]){
            tarjan(i.first, u);
            low[u] = min(low[u], low[i.first]);
            if(dfn[u] < low[i.first]){
                is_bridge[i.second] = true;
                is_bridge[i.second ^ 1] = true;
            }
        } else if(i.first != f){
            low[u] = min(low[u], dfn[i.first]);
        }
    }
}

bool vis[2000005];
void dfs(int u, int cnt){
    if(vis[u]) return;
    vis[u] = true;
    ans[cnt].push_back(u);
    for(auto i : gra[u]){
        if(!is_bridge[i.second]){
            dfs(i.first, cnt);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        gra[u].push_back(make_pair(v, cnt++));
        gra[v].push_back(make_pair(u, cnt++));
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i, -1);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i, ++dcc_cnt);
    }
    cout << dcc_cnt << endl;
    for(int i = 1; i <= dcc_cnt; i++){
        cout << ans[i].size() << " ";
        for(auto j : ans[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}