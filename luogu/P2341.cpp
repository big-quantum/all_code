#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gra[10005];
bool arr[10005];
bool vis[10005];
int cnt, ans;
void dfs(int u){
    if(vis[u]) return;
    vis[u] = true;
    for(auto i : gra[u]){
        dfs(i);
    }
    cnt++;
}
void dfs1(int u){
    if(vis[u]) return;
    vis[u] = true;
    for(auto i : gra[u]){
        dfs(i);
    }
    cnt++;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        gra[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(arr[i]) continue;
        dfs(i);
        if(cnt == n) ans++;
        else {
            for(int i = 1; i <= n; i++){
                if(vis[i]) arr[i] = true;
            }
        }
        memset(vis, false, sizeof(vis));
        cnt = 0;
    }
    cout << ans << endl;
    return 0;
}