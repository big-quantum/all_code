#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

//建树
int n, _next[MAXN * 4], ww[MAXN * 4], to[MAXN * 4], head[MAXN * 4], cnt;

void add(int f, int t, int w){
    to[++cnt] = t;
    ww[cnt] = w;
    _next[cnt] = head[f];
    head[f] = cnt;
}

//dfs
int val[MAXN];

void dfs(int x, int fa, int cur){
    val[x] = cur;
    for(int p = head[x]; p != 0; p = _next[p]){
        if(to[p] == fa) continue;
        dfs(to[p], x, cur ^ ww[p]);
    }
}

//diction_tree;
int tree[MAXN][2], cntt;

void insert_dict(int a){
    int cur = 1;
    for(int i = 31; i >= 0; i--){
        int bit = (a >> i) & 1;
        if(!tree[cur][bit]) tree[cur][bit] = cntt++;
        cur = tree[cur][bit];
    }
}

int find_dict(int a){
    int cur = 1, ans = 0;
    for(int i = 31; i >= 0; i--){
        int bit = (a >> i) & 1;
        if(tree[cur][bit ^ 1]){
            cur = tree[cur][bit ^ 1];
            ans += 1 << i;
        } else {
            cur = tree[cur][bit];
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, 0, 0);
    for(int i = 1; i <= n; i++){
        insert_dict(val[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, find_dict(val[i]));
    }
    cout << ans << endl;
    return 0;
}