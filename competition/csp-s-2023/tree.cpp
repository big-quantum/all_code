#include<bits/stdc++.h>
using namespace std;

int n, a[10005], maxn;
int main(){
    cin >> n;
    for(int i = 1;i <= n - 1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        maxn = max(a, maxn);
    }
    cout << maxn << endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// struct Edge {
//     int from_id, to, w;
// } edge[1000005];

// int head[1000005], tot, dis[1000005];
// bool vis[1000005];

// void add(int from, int to, int w){
//     edge[++tot].to = to;
//     edge[tot].w = w;
//     edge[tot].from_id = head[from];
//     head[from] = tot;  
// }

// priority_queue<pair<int, int>> q;

// void dij() {
//     for(int i = 1; i <= n; i++) {
//         dis[i] = INT_MAX;
//     }
//     dis[s] = 0;
//     q.push(make_pair(-val[s], s));
//     while(!q.empty()) {
//         pair<int, int> tmp = q.top();
//         q.pop();
//         int x = tmp.second;
//         if(vis[x]) continue;
//         vis[x] = false;
//         for(int i = head[x]; i; i = edge[i].from_id) {
//             int y = edge[i].to;
//             dis[x] = (dis[x], dis[y] + edge[i].w);
//             if(!vis[y]){
//                 q.push(make_pair())
//             }
//         }
//     }

// }

// int n, m, s;

// int main() {
//     cin >> n >> m >> s;
//     for (int i = 1; i <= m; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         add(u, v, w);
//     }
    
//     dij();

//     for (int i = 1; i <= n; i++) {
//         cout << dis[i] << " ";
//     }

//     return 0;
// }