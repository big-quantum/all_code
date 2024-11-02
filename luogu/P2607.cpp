#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n, head[MAXN], _next[MAXN], to[MAXN], in[MAXN], cnt = 1, in[MAXN], attack[MAXN], fa[MAXN];

void add(int u, int v){
    to[cnt] = v;
    in[v]++;
    _next[cnt] = head[u];
    head[u] = cnt++;
}

bool vis[MAXN], h;

void find(int x){
    vis[x] = true;
    if(vis[fa[x]]) h = x;
    else find(fa[x]);
    return;
}

void dp(int x){
    
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> attack[i] >> fa[i];
        add(fa[i], i);
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        find(i);
    }

    return 0;
}