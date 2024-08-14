#include<bits/stdc++.h>//over
using namespace std;
const int MAXN = 100005;

int head[MAXN], _next[MAXN], to[MAXN], cnt, tim[MAXN];

void add(int u, int v, int w){
    to[++cnt] = v;
    tim[cnt] = w;
    _next[cnt] = head[u];
    head[u] = cnt;
}

long long dist[10005];
bool in_queue[MAXN];
map<int, vector<pair<int, int>>> memory;

long long spfa(int from, int arr){
    memset(dist, 0x4f, sizeof(dist));
    dist[from] = 0;
    queue<int> q;
    q.push(from);
    memset(in_queue, false, sizeof(in_queue));
    in_queue[from] = true;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        in_queue[p] = false;
        for(int i = head[p]; i != 0; i = _next[i]){
            int t = to[i], w = tim[i];
            if(dist[t] > dist[p] + w){
                dist[t] = dist[p] + w;
                if(!in_queue[t]){
                    in_queue[t] = true;
                    q.push(t);
                }
            }
        }
    }
    return dist[arr];
}

int v, e, q;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d%d", &v, &e);
    for(int i = 1; i <= e; i++){
        int u, to, t;
        scanf("%d%d%d", &u, &to, &t);
        add(u, to, t);
        add(to, u, t);
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        int s, t;
        scanf("%d%d", &s, &t);
        printf("%lld\n", spfa(s, t));
    }
    return 0;
}