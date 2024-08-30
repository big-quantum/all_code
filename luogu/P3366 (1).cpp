#include<bits/stdc++.h>//kruskal
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

void kruskal(){
    init();
    sort(gra.begin(), gra.end());
    for(auto i : gra){
        int x = find(i.second.first), y = find(i.second.second);
        if(x == y) continue;
        fa[x] = y;//merge
        ans += i.first;
        if(++cnt == n - 1){
            break;
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
    kruskal();
    if(cnt < n - 1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}