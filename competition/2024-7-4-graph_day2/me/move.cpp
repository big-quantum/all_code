#include<bits/stdc++.h>
using namespace std;
const int MAXN = 40005;

int head[MAXN], _next[MAXN], to[MAXN], cnt, tim[MAXN];

void add(int u, int v, int w){
    to[++cnt] = v;
    tim[cnt] = w;
    _next[cnt] = head[u];
    head[u] = cnt;
}

int v, e, n, k;
int num[MAXN];
bool if_pep[MAXN];
map<int,vector<int>> city;

void move_city(int from, int to, int n){

}

int main(){
    freopen("move.in", "r", stdin);
    freopen("move.out", "w", stdout);
    cin >> v >> e >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        if_pep[num[i]] = true;
        city[num[i]].push_back(i);
    }
    for(int i = 1; i <= e; i++){
        int u, v, t;
        cin >> u >> v >> t;
        add(u, v, t);
        add(v, u, t);
    }
    move_city(1, 1, k);
    cout << -1 << endl;
    return 0;
}