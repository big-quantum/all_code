#include<bits/stdc++.h>
using namespace std;
/*
建图,将跳板的起点和终点连边,终点和它右上方的跳板的起点和(n,n)连边
起点和所有跳板的起点和(n,n)连边
边权为|y2 - y1| + |x2 - x1|
在这张图上跑最短路，会爆，但比广搜好。
*/
int n, p;
map<pair<int, int>, pair<int, int>> jump;
bool flag;
int dx[2] = {1, 0}, dy[2] = {0, 1};
/*
map<int, pair<int, int>> _hash;
int cntt;

int _next[100005], head[100005], to[100005], cnt;
void add(int u, int v){
    to[++cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt;
}
*/
int main(){
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> n >> p;
    for(int i = 1; i <= p; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        jump[make_pair(x1, y1)] = make_pair(x2, y2);
        /*_hash[++cntt] = make_pair(x1, y1);
        _hash[++cntt] = make_pair(x2, y2);
        add(cntt - 2, cntt - 1);*/
    }//bfs
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, 0)));
    while(!q.empty() && flag != true){
        pair<int, pair<int, int>> pos = q.front(); 
        if(pos.second.first == n && pos.second.second == n){
            cout << pos.first << endl;
            flag = true;
            continue;
        }
        q.pop();
        for(int i = 0; i < 2; i++){
            int xx = pos.second.first + dx[i], yy = pos.second.second + dy[i];
            pair<int, int> npos = {xx, yy};
            if(xx >= 0 && xx <= n && yy >= 0 && yy <= n) {
                if(jump.find(npos) != jump.end()) {
                    q.push(make_pair(pos.first + 1, jump[npos]));
                } else {
                    q.push(make_pair(pos.first + 1, npos));
                }
            }
        }
    }


    return 0;
}