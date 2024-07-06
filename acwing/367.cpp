#include<bits/stdc++.h>
using namespace std;

int n, head[1005], cnt, stk[10005], dfn[10005], low[10005], tot, top, scccnt;
int idin[1005],idout[1005], id[10005];
bool instk[10005];
struct node{
    int next,to;
}edge[10005];

void add(int from, int to){
    edge[++cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

void tarjan(int u){
    dfn[u] = ++tot;
    low[u] = tot;
    stk[++top] = u;
    instk[u] = true;
    for(int i = head[u]; i != 0; i = edge[i].next){
        int x = edge[i].to;
        if(!dfn[x]){
            tarjan(x);
            low[u] = min(low[u], low[x]);
        } else if(instk[x]){
            low[u] = min(low[u], dfn[x]);
        }
    }
    if(dfn[u] == low[u]){ 
        scccnt++;
        int x;
        do {
            x = stk[top--];
            instk[x] = false;
            id[x] = scccnt;
        } while(x != u);
    }
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++){
        int out;
        cin >> out; 
        while (out != 0){
            add(i, out);
            cin >> out;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++){
        for(int j = head[i]; j != 0; j = edge[j].next){
            int k = edge[j].to, a = id[i], b = id[k];
            if(a != b){
                idout[a]++;
                idin[b]++;
            }
        }
    }
    
    int in = 0, out = 0;
    for (int i = 1; i <= scccnt; i++){
        if(!idout[i]) out++;
        if(!idin[i]) in++;
    }
    
    cout << in << endl;
    if(scccnt == 1){
        cout << 0 << endl;
    } else {
        cout << max(in, out) << endl;
    }

    return 0;
}