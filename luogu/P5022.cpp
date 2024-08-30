#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;

int n, m, cnt;
bool vis[MAXN], flag, crl[MAXN];
vector<int> point[MAXN], ans, ans1;
vector<pair<int, int>> edge;
void dfs1(int u, int f){
    if(vis[u]) return;
    vis[u] = true;
    ans.push_back(u);
    for(auto i : point[u]){
        if(i != f && !vis[i]) {
            dfs1(i, u);
        }
    }
}

int dfn[MAXN], low[MAXN], times, stk[MAXN], top;
int scc_cnt, id[MAXN];
bool instk[MAXN];
void tarjan(int u, int fa){
    dfn[u] = low[u] = ++times;
    stk[++top] = u;
    int topp = top;
    instk[u] = true;
    for(auto i : point[u]){
        if(!dfn[i]){
            tarjan(i, u);
            low[u] = min(low[u], low[i]);
        } else if(instk[i] && i != fa){
            low[u] = min(low[u], dfn[i]);
        }
    }
    if(low[u] == dfn[u]){ 
        scc_cnt++;
        int tmp, cnt = 0;
        if(topp == top){
            id[stk[top--]] = scc_cnt;
            instk[stk[top + 1]] = false;
        } else do{
            tmp = stk[top--];
            crl[tmp] = true;
            id[tmp] = scc_cnt;
            instk[tmp] = false;
        } while (tmp != u);
    }
}

int flagfrom = -1, flagto = -1;
void dfs2(int u, int f){
    if(vis[u]) return;
    vis[u] = true;
    ans1.push_back(u);
    for(auto i : point[u]){
        if(i != f && !vis[i] && (u != flagfrom || i != flagto) && (u != flagto || i != flagfrom)) {
            dfs2(i, u);
        }
    }
    vis[u] = false;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int from, to;
        cin >> from >> to;
        point[from].push_back(to);
        point[to].push_back(from);
        edge.push_back(make_pair(from, to));
    }
    for(int i = 1; i <= n; i++){
        sort(point[i].begin(), point[i].end());
    }
    if(m == n - 1){
        dfs1(1, -1);
    } else {
        ans.push_back(MAXN);
        tarjan(1, -1);
        for (auto e : edge){
            if(crl[e.first] && crl[e.second]){
                flagfrom = e.first;
                flagto = e.second;
                dfs2(1, -1);
                bool flag = false;
                for(int i = 0; i < n; i++){
                    if(ans[i] > ans1[i]){
                        flag = true;
                        break;
                    }
                    if(ans[i] < ans1[i]) break;
                }
                if(flag) swap(ans, ans1);
                ans1.clear();
            }   
        }
    }
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}