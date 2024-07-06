#include<bits/stdc++.h>
using namespace std;
const int MAXN = 50005;

int n, t, mapp[105][105];

struct node{
    int next,to;
}edge[MAXN];

int head[MAXN], cnt;

void add(int from, int to){
    edge[++cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

int transform(int i, int j){
    return n *(i - 1) + j;
}

int p[MAXN];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool vis[MAXN];

/*
bool match(int x, int y){
    for(int i = 0; i <= 3; i++){
        int xx = x + dx[i], yy = y + dy[i];
        int num = transform(xx, yy);
        if(!mapp[xx][yy] && !vis[num]){
            //mapp[xx][yy] = -1;
            vis[num] = true;
            if(p[num] == 0 || match(p[num] / n, p[num] % n)){
                p[num] = transform(x, y);
                return true;
            }
        }
    }
    return false;
}

int hungarian(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            memset(vis, false, sizeof(vis));
            if(match(i, j)){
                cnt++;
            }
        }
    }
    return cnt / 2;
}
*/

bool match(int x){
    for(int i = head[x]; i; i = edge[i].next){
        int to = edge[i].to;
        if(!vis[to]){
            vis[to] = true;
            if(p[to] == 0 || match(p[to])){
                p[to] = x;
                return true;
            }
        }
    }
    return false;
}

int hungarian(){
    int cnt = 0;
    for(int i = 1; i <= n * n; i++){
        memset(vis, false, sizeof(vis));
        if(match(i)){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    cin >> n >> t;
    for(int i = 1; i <= t; i++){
        int x, y;
        cin >> x >> y;
        mapp[x][y] = -1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mapp[i][j] == -1) continue;
            int u = transform(i, j);
            for(int k = 0; k < 4; k++){
                int xx = i + dx[k], yy = j + dy[k];
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= n && mapp[xx][yy] != -1){
                    int v = transform(xx, yy);
                    add(u, v);
                }
            }
        }
    }

    cout << hungarian() / 2<< endl;
    return 0;
}