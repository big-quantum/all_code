#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int to, from_id, w;
} edge[200050];

int tot, head[200050];
int n, m, s, dis[200050];
bool vis[200050];

void add(int from, int to, int w) {
    edge[++tot].to = to;
    edge[tot].w = w;
    edge[tot].from_id = head[from];
    head[from] = tot;
}

priority_queue<pair<int, int>> q;

void dij(){
    for(int i = 0; i <= 100002; i++){
        dis[i] = 0x7fffffff;
    }
    dis[s] = 0;
    q.push(make_pair(-dis[s], s));
    while (!q.empty()) {
        pair<int, int> tmp = q.top();
        q.pop();
        int x = tmp.second;

        if(vis[x]) continue;
        vis[x] = 1;
        
        for (int i = head[x]; i; i = edge[i].from_id) {
            int y = edge[i].to;
            dis[y] = min(dis[y], dis[x] + edge[i].w);
            if(!vis[y]) {
                q.push(make_pair(-dis[y], y));
            }
        }
        
    }
    
}
int main() {
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dij();
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
    return 0;
}