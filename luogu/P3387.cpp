#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, m, dfn[MAXN], low[MAXN], times = 1, stk[MAXN], top, num[MAXN], id[MAXN], scc_cnt, u[MAXN], v[MAXN];
vector<int> gra[MAXN], new_gra[MAXN];
bool instk[MAXN];
void tarjan(int u){
    dfn[u] = low[u] = times++;
    instk[u] = true;
    stk[top++] = u;
    for(auto v : gra[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instk[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    int tmp;
    scc_cnt++;
    do{
        tmp = stk[--top];
        instk[tmp] = false;
        id[tmp] = scc_cnt;
    } while (tmp != u);
    
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i];
        gra[u[i]].push_back(v[i]);
    }
    for(int i = 1; i <= m; i++){
        if(id[u[i]] != id[v[i]]){
            new_gra[u[i]].push_back(v[i]);
        }
    }
    return 0;
}