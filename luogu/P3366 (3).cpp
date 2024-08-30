#include<bits/stdc++.h>//boruvka
using namespace std;

int n, m, fa[5005], cnt;
vector<pair<int, pair<int, int>>> gra;
long long ans;

void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
}

int find(int x){
    if(x != fa[x]) return fa[x] = find(fa[x]);
    else return x;
}

bool cmp(int i, int j){
    if(j == -1) return true;
    if(gra[i].first != gra[j].first) return gra[i].first < gra[j].first;
    else return i < j;
}

int best[300005];
bool vis[300005], update;
void boruvka(){
    init();
    update = true;
    while(update){
        update = false;
        memset(best, -1, sizeof(best));
        for(int i = 0; i < m; i++){
            if(vis[i]) continue;
            int x = find(gra[i].second.first), y = find(gra[i].second.second);
            if(x == y) continue;
            if(cmp(i, best[y])) best[y] = i;
            if(cmp(i, best[x])) best[x] = i;
        }
        for(int i = 1; i <= n; i++){
            if(best[i] != -1 && !vis[best[i]]){
                update = true;
                cnt++;
                ans += gra[best[i]].first;
                vis[best[i]] = true;
                fa[find(gra[best[i]].second.first)] = find(gra[best[i]].second.second);
            }
        }
    }
    
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        gra.push_back(make_pair(z, make_pair(x, y)));
    }
    boruvka();
    if(cnt < n - 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}