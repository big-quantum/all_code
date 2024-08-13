#include<bits/stdc++.h>
using namespace std;

int mapp[205][205], n, m, d[205], a[205], b[205], c[205];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int dist[205];
bool vis[205];
int dij1(int s){
    for(int i = 0; i <= n; i++){
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    memset(vis, false, sizeof(vis));
    q.push(make_pair(0, s));
    while(!q.empty()){
        int pos = q.top().second, tt = q.top().first;
        q.pop();
        if(vis[pos]) continue;
        vis[pos] = true;
        for(int i = 1; i <= n; i++){
            if(mapp[pos][i] != INT_MAX) dist[i] = min(dist[i], dist[pos] + mapp[pos][i]);
            if(!vis[i]){
                q.push(make_pair(dist[i], i));
            }
        }
    }
    return dist[n];
}

int dij2(int s){
    for(int i = 0; i <= n; i++){
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    memset(vis, false, sizeof(vis));
    q.push(make_pair(0, s));
    while(!q.empty()){
        int pos = q.top().second, tt = q.top().first;
        q.pop();
        if(vis[pos]) continue;
        vis[pos] = true;
        for(int i = 1; i <= n; i++){
            if(mapp[pos][i] != INT_MAX) dist[i] = min(dist[i], dist[pos] + mapp[pos][i]);
            if(!vis[i]){
                q.push(make_pair(dist[i], i));
            }
        }
    }
    return dist[1];
}
int main(){
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n + 2; i++){
        for(int j = 1; j <= n + 2; j++){
            mapp[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i <= m; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        mapp[a[i]][b[i]] = min(mapp[a[i]][b[i]], c[i]);
    }
    int ans = INT_MAX;
    ans = min(dij1(1) + dij2(n), ans);
    cout << ans << endl;
    for(int i = 1; i <= m; i++){
        for(int i = 1; i <= n + 2; i++){
            for(int j = 1; j <= n + 2; j++){
                mapp[i][j] = INT_MAX;
            }
        }
        mapp[b[i]][a[i]] = c[i] + d[i];
        for(int j = 1; j <= m; j++){
            if(j != i) mapp[a[j]][b[j]] = min(mapp[a[j]][b[j]], c[j]);
        }
        ans = min(dij1(1) + dij2(n), ans);
    }
    cout << ans << endl;
    return 0;
}
