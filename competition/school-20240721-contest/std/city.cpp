#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 10007, M = 100007;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//有向图强连通分量，维护每个连通块内点的数量
void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    in_stk[u] = true;

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u]) {
        int y;
        scc_cnt++;
        do {
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt]++;
        } while (y != u);

    }
}

int main() {
    freopen("city.in", "r", stdin);
    freopen("city.out", "w", stdout);

    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    ll sum = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        int x = sz[i];
        sum += (ll) (x - 1) * x / 2;   //每个连通块内部两两都是便利对，求一遍组合数C(x, 2)
    }

    printf("%lld\n", sum);

    fclose(stdin);
    fclose(stdout);

    return 0;
}