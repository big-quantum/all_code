#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int point[105];
bool p_check[105];
vector<int> leaf, arr_leaf;
bool not_arr_leaf[105];

int _next[1005], head[1005], to[1005], cnt;
void add(int u, int v){
    to[++cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt;
}

void dfs1(int u, int fa, int mm){
    if(mm == 0){
        for(auto i : leaf){
            if(i == u){
                arr_leaf.push_back(i);
                not_arr_leaf[i] = true;
                continue;
            }
        }
    }
    for(int i = head[u]; i != 0 && to[i] != fa; i = _next[i]){
        if(p_check[i]) dfs1(to[i], u, mm - 2);
        else dfs1(to[i], u, mm - 1);
    }
}

int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int a;
        cin >> a;
        p_check[a] = true;
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
        point[u]++;
        point[v]++;
    }
    //cout << point[1] << endl;
    //leaf_check
    for (int i = 1; i <= n; i++){
        if(point[i] == 1) leaf.push_back(i);
        else not_arr_leaf[i] = true;
    }
    dfs1(1, 1, m);
    int minn = 999;
    for (int i = 1; i <= n; i++){
        if(!not_arr_leaf[i]){
            if(i < minn) minn = i;
        }
    }
    if(minn != 999) cout << minn << endl;
    else cout << 0 << endl;
    minn = 999;
    for(auto i : arr_leaf){
        if(i < minn) minn = i;
    }
    if(minn != 999) cout << minn << endl;
    else cout << 0 << endl;
    return 0;
}