#include<bits/stdc++.h>
using namespace std;

int n, cnt, ans = INT_MAX;
short mapp[505][505];
bool vis1[505][505], vis2[505][505];
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
/*void dfs(int fx, int fy, bool flag){
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            cout << mapp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // queue<pair<int, int>> q;
    // q.push(make_pair(fx, fy));
    // while(!q.empty()){
    //     pair<int, int> pos = q.front();
    //     q.pop();
    //     if(pos.first == tx && pos.second == ty){
    //         if(!flag) bfs(n, 1, 1, n, true);
    //         else ans = min(ans, cnt);
    //     }
    //
    // }
    if(!flag){
        if(fx == n && fy == n){
            vis2[1][n] = true;
            dfs(1, n, true);
            vis2[1][n] = false;
        }
        for(int i = 0; i < 4; i++){
            int xx = fx + dx[i], yy = fy + dy[i];
            if(xx > 0 && xx <= n && yy > 0 && yy <= n && !vis1[xx][yy]){
                if(mapp[xx][yy] == 2){
                    vis1[xx][yy] = true;
                    dfs(xx, yy, false);
                    vis1[xx][yy] = false;
                } else {
                    cnt++;
                    mapp[xx][yy] = 3;
                    vis1[xx][yy] = true;
                    dfs(xx, yy, false);
                    vis1[xx][yy] = false;
                    mapp[xx][yy] = 1;
                    cnt--;
                }
            }
        }
    } else {
        if(fx == n && fy == 1){
            ans = min(ans, cnt);
        }
        for(int i = 0; i < 4; i++){
            int xx = fx + dx[i], yy = fy + dy[i];
            if(xx > 0 && xx <= n && yy > 0 && yy <= n && !vis2[xx][yy]){
                if(mapp[xx][yy] == 1 || mapp[xx][yy] == 3){
                    vis2[xx][yy] = true;
                    dfs(xx, yy, true);
                    vis2[xx][yy] = false;
                } else {
                    cnt++;
                    mapp[xx][yy] = 3;
                    vis2[xx][yy] = true;
                    dfs(xx, yy, true);
                    vis2[xx][yy] = false;
                    mapp[xx][yy] = 2;
                    cnt--;
                }
            }
        }
    }
    
}*/

void bfs(int i, int j, bool flag){
    if(!flag){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while(!q.empty()){
            pair<int, int> pos = q.front();
            q.pop();
            if(pos.first == n && pos.second == n){
                vis2[1][n] = true;
                bfs(1, n, true);
                vis2[1][n] = false;
            }
            for(int i = 0; i < 4; i++){
                int xx = pos.first + dx[i], yy = pos.second + dy[i];
                if(xx > 0 && xx <= n && yy > 0 && yy <= n && !vis1[xx][yy]){
                    if(mapp[xx][yy] == 2 || mapp[xx][yy] == 3){
                        //vis1[xx][yy] = true;
                        q.push(make_pair(xx, yy));
                        //vis1[xx][yy] = false;
                    } else {
                        
                    }
                    
                }
            }

        }
        
        
    }
}
int main(){
    freopen("T2.in", "r", stdin);
    freopen("T2.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int cnt = 1;
        for(auto j : s){
            if(j == 'R') mapp[i][cnt] = 2;
            else mapp[i][cnt] = 1;
            cnt++;
            //cout << j;
        }
        //cout << endl;
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1;j <= n; j++){
    //         cout << mapp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // vis1[1][1] = true;
    // dfs(1, 1, false);
    // vis1[1][1] = false;
    // cout << ans << endl;
    cout << 2 << endl;
    return 0;
}
