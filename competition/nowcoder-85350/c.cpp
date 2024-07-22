#include<bits/stdc++.h>
using namespace std;

int n, m, q, tmp;
pair<int, pair<int, int> > edge[200005];
int id[200005], ans[200005];

void _init(){
    for(int i = 1; i <= n; i++){
        id[i] = i;
    }
}

int find(int a){
    if(id[a] == a){
        return a;
    } else {
        id[a] = find(id[a]);
        return id[a];
    }
}

void merge(int a, int b){
    if(id[find(a)] != find(b)){
        tmp--;
    }
    id[find(a)] = find(b);
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.first > b.first;
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = make_pair(w, make_pair(u, v));
    }
    sort(edge + 1, edge + 1 + m, cmp);
    for(int i = 1; i <= q; i++){
        int l, r;
        tmp = n;
        bool flag = false;
        cin >> l >> r;
        if(ans[r] != 0){
            cout << ans[r] << endl;
            continue;
        }
        _init();
        for(int j = 1; j <= n - r; j++){
            merge(edge[j].second.first, edge[j].second.second);
        }
        for(int j = n - r + 1; j <= m; j++){
            merge(edge[j].second.first, edge[j].second.second);
            if(tmp == r){
                ans[r] = edge[j].first;
                cout << edge[j].first << endl;
                flag = true;
                break;
            } 
            if(tmp < r) break;
        }
        if(!flag) cout << "NO ANSWER" << endl;
    }
    
    return 0;
}
