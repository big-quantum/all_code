#include<bits/stdc++.h>
using namespace std;

int n, m, head[6005], _next[6005], to[6005], cnt = 1, t1, s1, t2, s2;
void add(int u, int v){
    to[cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt++;
}

int dist[3][3005];
bool vis[3005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
void dij(int p, int cntt){
    for(int i = 1; i <= n; i++){
        dist[cntt][i] = INT_MAX;
        vis[i] = false;
    }
    dist[cntt][p] = 0;
    q.push(make_pair(0, p));
    while (!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u]; i != 0; i = _next[i]){
            int v = to[i];
            if(dist[cntt][v] > dist[cntt][u] + 1)
            dist[cntt][v] = dist[cntt][u] + 1;
            if(!vis[v]) q.push(make_pair(dist[cntt][v], v));
        }
    }
    
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    cin >> s1 >> t1 >> s2 >> t2;
    dij(1, 0);
    if(dist[0][s1] > t1 || dist[0][s2] > t2){
        cout << -1 << endl;
        return 0;
    }
    dij(s1, 1);
    dij(s2, 2);
    int ans = m;
    for(int i = 1; i <= n; i++){
        if(dist[0][i] + dist[1][i] <= t1 && dist[0][i] + dist[2][i] <= t2)
        ans = min(ans, dist[0][i] + dist[1][i] + dist[2][i]);
    }
    cout << m - ans << endl;
    return 0;
}
