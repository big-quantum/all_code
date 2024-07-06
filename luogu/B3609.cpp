#include<bits/stdc++.h>
using namespace std;

int head[10005], cnt;

struct edge{
    int to, next;
}e[100005];

void add(int from, int to){
    e[++cnt].to = to;
    e[cnt].next = head[from];
    head[from] = cnt;
}

int n, m;
int stk[100005], top, dfn[100005], low[100005], t, num[100005];
bool instk[100005], vis[100005];
int scccnt;
vector<int> scc[100005];

void tarjan(int u){
    stk[++top] = u;
    instk[u] = true;
    dfn[u] = ++t;
    low[u] = t;
    for(int i = head[u]; i != 0; i = e[i].next){
        int to = e[i].to;
        if(!dfn[to]){
            tarjan(to);
            low[u] = min(low[u], low[to]);
        } else if(instk[to]){
            low[u] = min(low[u], dfn[to]); 
        }
    }

    if(dfn[u] == low[u]){
        ++scccnt;
        int x;
        do {
            x = stk[top--];
            num[x] = scccnt;
            instk[x] = false;
            scc[scccnt].push_back(x);
        } while(x != u);

    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i);
    }

    cout << scccnt << endl;
    for(int i = 1, pos; i <= n; i++) {
        pos = num[i];
        if(vis[pos]) continue;
        vis[pos] = true;
        sort(scc[pos].begin(), scc[pos].end());
        for (auto j = scc[pos].begin(); j != scc[pos].end(); j++) {
            cout << *j << " ";
        }
        // for(int point : scc[i]){
        //     cout << point << " ";
        // }
        cout << endl;
    }

    return 0;
}
