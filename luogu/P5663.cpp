#include<bits/stdc++.h>
using namespace std;

int n, m, q;
int head[100005], _next[200005], to[200005], cnt = 1;
void add(int u, int v){
    to[cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt++;
}

int dist_ji[100005], dist_ou[100005];
bool vis[100005];
void dij(int p){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for(int i = 1; i <= n; i++){
        dist_ji[i] = INT_MAX;
        dist_ou[i] = INT_MAX;
    }
    q.push(make_pair(0, p));
    while(!q.empty()){
        int u = q.top().second;
        int dis = q.top().first;
        q.pop();
        for(int i = head[u]; i != 0; i = _next[i]){
            int v = to[i];
            if(dis % 2 == 0){
                if(dist_ji[v] > dis + 1){
                    dist_ji[v] = dis + 1;
                    q.push(make_pair(dist_ji[v], v));
                }
            } else {
                if(dist_ou[v] > dis + 1){
                    dist_ou[v] = dis + 1;
                    q.push(make_pair(dist_ou[v], v));
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dij(1);
    for(int i = 1; i <= q; i++){
        int a, l;
        cin >> a >> l;
        if(l % 2 == 1){
            if(l >= dist_ji[a]) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if(l >= dist_ou[a]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}