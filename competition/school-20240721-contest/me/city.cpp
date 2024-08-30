#include<bits/stdc++.h>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
int from[100005], to[100005], _next[10005], cnt, ans;

void add(int u, int v){
    to[++cnt] = v;
    _next[cnt] = from[u];
    from[u] = cnt;
}

int dfn[10005], low[10005], _time, scccnt;
bool instk[10005];
int stk[10005], top;

void tarjan(int p){
    dfn[p] = ++_time;
    low[p] = _time;
    stk[++top] = p;
    instk[p] = true;
    for(int i = from[p]; i != -1; i = _next[i]){
        int v = to[i];
        if(!dfn[v]){
            tarjan(v);
            low[p] = min(low[p], low[v]);
        } else if(instk[v]){
            low[p] = min(low[p], dfn[v]);
        }
    }
    if(low[p] == dfn[p]){
        scccnt++;
        int cntt = 0, x;
        do {
            x = stk[top--];
            instk[x] = false;
            cntt++;
        }while(x != p);
        ans += (cntt * (cntt - 1) / 2);
    }
}

int main(){
	cin >> n >> m;
    memset(_next, -1, sizeof(_next));
    for(int i = 1; i <= m; i++){
        int f, t;
        cin >> f >> t;
        add(f, t);
    }
    tarjan(1);
    cout << ans << endl;
	return 0;
}
