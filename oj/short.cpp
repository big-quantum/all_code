#include<bits/stdc++.h>
using namespace std;

int n, m, mapp[50][50], k, ans = INT_MAX;
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
bool vis[50][50];

void bfs(int x, int y, int step, int kk){
    if(x == n && y == m) ans = min(step, ans);
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx > 0 && xx <= n && yy > 0 && yy <= m && vis[xx][yy] == false) {
            if(mapp[xx][yy] == 1 && kk > 0) {
                vis[xx][yy] = true;
                bfs(xx, yy, step + 1, kk - 1);
                vis[xx][yy] = false;
            } else {
                if(mapp[xx][yy] == 0){
                    vis[xx][yy] = true;
                    bfs(xx, yy, step + 1, kk);
                    vis[xx][yy] = false;
                }
            }
        }
    }
}

int main(){
    freopen("short.in", "r", stdin);
    freopen("short.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mapp[i][j];
        }
    }
    
    bfs(1, 1, 0, k);

    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}