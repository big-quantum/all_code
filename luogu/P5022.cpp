#include<bits/stdc++.h>
using namespace std;

int n, m, ans[5005], cnt;
bool vis[5005];
vector<int> point[5005];

void dfs1(int u, int fa){
    if(vis[u]){
        return;
    }
    vis[u] = true;
    ans[++cnt] = u;
    for(auto i : point[u]){
        if(i == fa) continue;
        else {
            dfs1(i, u);
        }
    }
}
void dfs2(int u, int fa){
    vis[u] = true;
    for(auto i : point[u]){
        if(i == fa) continue;
        if(vis[i]){
            flag = true;
            crl[u] = true;
            crl[i] = true;
            return;
        }
        dfs2(i, u);
        if(flag && crl[i]){
            crl[u] = true;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int from, to;
        cin >> from >> to;
        point[from].push_back(to);
        point[to].push_back(from);
    }
    for(int i = 1; i <= n; i++){
        sort(point[i].begin(), point[i].end());
    }
    if(m == n - 1){
        dfs1(1, 0);
    } else {

    }
    
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}