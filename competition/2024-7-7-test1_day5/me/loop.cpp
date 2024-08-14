#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

int n, m;
bool arr[MAXN];
int _next[MAXN], head[MAXN], to[MAXN], tim[MAXN], cnt;
void add(int u, int v, int w){
    to[++cnt] = v;
    tim[cnt] = w;
    _next[cnt] = head[u];
    head[u] = cnt;
}

bool vis[MAXN];/*
void dfs(int p){
    vis[p]= true;
    for(int i = head[p]; i != 0; i = _next[i]){
        if(vis[to[i]]) arr[to[i]] = true;
        else dfs(to[i]);
    }
}*/

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int dist[MAXN];
int dij(int s){
    for(int i = 0; i <= n; i++){
        dist[i] = INT_MAX;
    }
    memset(vis, false, sizeof(vis));
    q.push(make_pair(0, s));
    while(!q.empty()){
        int pos = q.top().second, tt = q.top().first;
        q.pop();
        if(vis[pos]) continue;
        vis[pos] = true;
        for(int i = head[pos]; i != 0; i = _next[i]){
            int v = to[i];
            dist[v] = min(dist[v], tt + tim[i]);
            if(!vis[v]){
                q.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[s];
}

int main(){
    freopen("loop.in", "r", stdin);
    freopen("loop.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    //dfs(1);
    for(int i = 1; i <= n; i++){
        //if(arr[i]) cout << dij(i) << endl;
        //else cout << -1 << endl;
        int tmp = dij(i);
        if(tmp != INT_MAX){
            cout << tmp << endl;
        } else{
            cout << -1 << endl;
        }
    }
    return 0;
}