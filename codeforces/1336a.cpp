#include<bits/stdc++.h>
using namespace std;

int n, k, dep[1005], siz[200005];
long long ans;
vector<int> tree[200005];
bool vis[200005];
priority_queue<long long> q;

void dfs(int u, int f, int deep){
    if(vis[u]) return;
    siz[u]++;
    vis[u] = true;
    for(auto i : tree[u]){
        if(i != f){
            dfs(i, u, deep + 1);
            siz[u] += siz[i];
        }
    }
    q.push((long long)(deep - siz[u]));
    return;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int a, b; 
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, -1, 1);
    for(int i = 1; i <= k; i++){
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}