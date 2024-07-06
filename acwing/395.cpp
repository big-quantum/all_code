#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

struct node{
    int next, to;
}edge[MAXN];
int f, r, head[MAXN], cnt, ttime;

void add(int from, int to){
    edge[++cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt; 
}

int dfn[MAXN], low[MAXN], stk[MAXN], top;
bool is_bridge[MAXN];

void tarjan(int u, int from){
    dfn[u] = ++ttime;
    low[u] = ttime;
    stk[++top] = u;
    for(int i = head[u]; i != 0; i = edge[i].next){
        int t = edge[i].to;
        if(!dfn[t]){
            tarjan(t, i);
            low[t] = min(low[t], low[u]);
            if(low[t] > dfn[u]){
                is_bridge[i] = true;
                is_bridge[i ^ 1] = true;
            }
        } else if(i != from ^ 1){
            
        }
    }
}

int main(){
    cin >> f >> r;

    return 0;
}