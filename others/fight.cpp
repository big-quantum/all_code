#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, m, id[MAXN], in[MAXN], out[MAXN];
struct node{
    int to, next;
}edge[MAXN];
int head[MAXN], cnt; 

void add(int from, int to){
    edge[++cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

int dfn[MAXN], low[MAXN], stk[MAXN], t, top, scccnt;
bool instk[MAXN], idvis[MAXN];

void tarjan(int u){
    dfn[u] = ++t;
    low[u] = t;
    stk[++top] = u;
    instk[u] = true;
    for(int i = head[u]; i != 0; i = edge[i].next){
        int v = edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instk[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(dfn[u] == low[u]){
        ++scccnt;
        int x;
        do{
            x = stk[top--]; 
            instk[x] = false;
            id[x] = scccnt;
        } while (x != u);
        
    }
}


int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int f, t;
        scanf("%d%d", &f, &t);
        add(f, t);
    }

    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = head[i]; j != 0; j = edge[j].next){
            int k = edge[j].to;
            int a = id[i], b = id[k];
            if(a != b){
                out[a]++;
                in[b]++;
            }
        }
    }
    
    int cnt = 0, idd;
    for(int i = 1; i <= scccnt; i++){
        if(!out[i]){
            cnt++;
            idd = id[i];
        }
    }

    if(cnt <= 1){
        int tot = 0;
        for(int i = 1; i <= n; i++){
            if(id[i] == idd) tot++;
        }
        cout << tot << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}