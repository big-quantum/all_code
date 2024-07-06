#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

int n, mtr[MAXN], sz[MAXN], nnum;
int head[MAXN], _next[MAXN], _to[MAXN], val[MAXN], cnt, ans;
vector<int> crr;

void add(int from, int to){
    _to[++cnt] = to;
    _next[cnt] = head[from];
    head[from] = cnt;
}

void dfs1(int p, int fa = 0){
    sz[p] = val[p];
    mtr[p] = 0;
    for(int q = head[p]; q != 0; q = _next[q]){
        if(_to[q] != fa){
            dfs1(_to[q], p);
            mtr[p] = max(mtr[p], sz[_to[q]]);
            sz[p] += sz[_to[q]];
        }
    }
    mtr[p] = max(mtr[p], nnum - sz[p]);
    if(mtr[p] <= nnum / 2){
        crr.push_back(p);
    }
}

void dfs2(int p, int fa, int step = 0) {
    ans += val[p] * step;
    for(int q = head[p]; q != 0; q = _next[q]){
        if(_to[q] != fa) dfs2(_to[q], p, step + 1);
    }
    
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int w,u,v;
        cin >> w >> u >> v;
        val[i] = w;
        nnum += w;
        if(u != 0) add(i, u), add(u, i);
        if(v != 0) add(i, v), add(v, i);
    }
    dfs1(1);
    dfs2(crr[0], 0);
    cout << ans << endl;

    return 0;
}