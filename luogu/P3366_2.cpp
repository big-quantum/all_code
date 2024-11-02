#include<bits/stdc++.h>//prim
using namespace std;

int n, m;
vector<pair<int, int>> gra[5005];//first -> to, second -> val
long long ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;//first -> val, second -> num
int dis[5005], vis[5005], cnt;

void prim(){
    for(int i = 2; i <= n; i++){
        dis[i] = INT_MAX;
    }
    q.push(make_pair(0, 1));
    while(!q.empty() && cnt < n){
        pair<int, int> p = q.top();
        q.pop();
        if(vis[p.second]) continue;
        vis[p.second] = true;
        cnt++;
        ans += p.first;
        for(auto to : gra[p.second]){
            if(dis[to.first] > to.second){
                dis[to.first] = to.second;
                q.push(make_pair(to.second, to.first));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        gra[x].push_back(make_pair(y, z));
        gra[y].push_back(make_pair(x, z));
    }
    prim();
    if(cnt < n) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}