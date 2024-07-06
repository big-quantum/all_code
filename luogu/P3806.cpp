#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
#define ll long long

ll next[MAXN], head[MAXN], val[MAXN], to[MAXN], cnt;

void add(int from, int to, int w){
    to[++cnt] = to;
    val[cnt] = w;
    next[cnt] = head[from];
    head[from] = cnt;
}

int sz[MAXN], mt;
bool vis[MAXN];

void dfs(int p, int fa){ // 找重心

}

int n, m, ask[MAXN];

int main(){
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= m; i++){
        cin >> ask[i];
    }


    return 0;
}