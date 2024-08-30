// #include<bits/stdc++.h>

// using namespace std;

// const int N = 100010, M = 400010;

// int n, m, s;
// int h[N], hs[N], e[M * 2], ne[M * 2], idx; // 邻接表
// int dfn[N], low[N], timestamp;
// int stk[N], top; // 栈
// int id[N], dcc_cnt;
// int dep[N], fa[N][18]; // lca
// int q[N]; // 队列

// void add(int h[], int a, int b) {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }

// void tarjan(int u, int from) {
//     dfn[u] = low[u] = ++timestamp;
//     stk[top++] = u;

//     for (int i = h[u]; i != -1; i = ne[i]) {
//         int j = e[i];

//         if (!dfn[j]) {
//             tarjan(j, i);
//             low[u] = min(low[u], low[j]);
//         } else if (i != (from ^ 1)) {
//             low[u] = min(low[u], dfn[j]);
//         }
//     }

//     if (dfn[u] == low[u]) {
//         dcc_cnt++;
//         int y;
//         do {
//             y = stk[--top];
//             id[y] = dcc_cnt;
//         } while (y != u);
//     }
// }

// void bfs() {
//     int hh = 0, tt = 0;
//     q[0] = 1;
//     dep[1] = 1;

//     while (hh <= tt) {
//         int t = q[hh++];

//         for (int i = hs[t]; i != -1; i = ne[i]) {
//             int j = e[i];
//             if (dep[j]) continue;

//             dep[j] = dep[t] + 1;
//             fa[j][0] = t;

//             for (int k = 1; k <= 17; k++) {
//                 fa[j][k] = fa[fa[j][k - 1]][k - 1];
//             }

//             q[++tt] = j;
//         }
//     }
// }

// int lca(int a, int b) {
//     if (dep[a] < dep[b]) swap(a, b);

//     for (int k = 17; k >= 0; k--) {
//         if (dep[fa[a][k]] >= dep[b]) {
//             a = fa[a][k];
//         }
//     }

//     if (a == b) {
//     	return a;
// 	}

//     for (int k = 17; k >= 0; k--) {
//         if (fa[a][k] != fa[b][k]) {
//             a = fa[a][k];
//             b = fa[b][k];
//         }
//     }

//     return fa[a][0];
// }

// int main() {
//     freopen("T2.in", "r", stdin);
//     freopen("T2.out", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);

//     cin >> n >> m;

//     // 初始化邻接表
//     memset(h, -1, sizeof h);
//     memset(hs, -1, sizeof hs);

//     // 构建原图
//     while (m--) {
//         int a, b;
//         cin >> a >> b;
//         add(h, a, b);
//         add(h, b, a);
//     }

//     // 求边双连通分量
//     tarjan(1, -1);

//     // 构建新图
//     for (int i = 1; i <= n; i++) {
//         for (int j = h[i]; j != -1; j = ne[j]) {
//             int k = e[j];
//             int a = id[i], b = id[k];
//             if (a != b) {
//                 add(hs, a, b);
//                 add(hs, b, a);
//             }
//         }
//     }

//     // 预处理深度和祖先信息
//     bfs();

//     cin >> s;
//     while (s--) {
//         int a, b;
//         cin >> a >> b;

//         a = id[a], b = id[b];
//         int p = lca(a, b); // 求最近公共祖先
//         cout << (dep[a] + dep[b] - 2 * dep[p]) << endl; // 计算距离
//     }

//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;
const int MAXN = 400005;

int n, m, cnt, cntt;
pair<int, int> edge[MAXN];
int _next[MAXN], head[MAXN], to[MAXN];
vector<int> tree[100005];
int dfn[MAXN], low[MAXN], stk[MAXN], top;
int id[MAXN], dcc_cnt;
int log_2[MAXN], dep[MAXN], fa[MAXN][20];
bool vis[MAXN];

void add(int u, int v) {
    to[cnt] = v;
    _next[cnt] = head[u];
    head[u] = cnt++;
}

// 修改1，检测割顶和桥，并缩点，tarjan调整
void tarjan(int u, int f) {
    dfn[u] = low[u] = ++cntt;
    stk[++top] = u;
    vis[u] = true;
    // 初始化 head 为 -1
    for (int i = head[u]; i != -1; i = _next[i]) {
        int j = to[i];
        if (j == f) { // 修改2，不返回父节点的边
            continue;
        }
        // j 未访问
        if (!dfn[j]) {
            tarjan(j, u);
            low[u] = min(low[u], low[j]);
        } else if (vis[j]) {  // j 在栈中，则更新 low 值
            low[u] = min(low[u], dfn[j]);
        }
    }
    if (low[u] == dfn[u]) {
        ++dcc_cnt;
        int tmp;
        do {
            tmp = stk[top--];
            id[tmp] = dcc_cnt;
            vis[tmp] = false;  // 修改3，出栈
        } while (tmp != u);
    }
}

// 修改4，初始化前向星、log、深度。
void init() {
    // 初始化为 -1
    memset(head, -1, sizeof(head));
    for (int i = 2; i <= n; i++) {
        // 预处理 log
        log_2[i] = log_2[i / 2] + 1;
    }
    for (int i = 1; i <= m; i++) {
        int a = id[edge[i].first], b = id[edge[i].second];
        // 只有 a 和 b 不在同一个强连通分量时，才添加树边
        if (a != b) {
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }
}

// 修改5，用DFS遍历生成LCA的fa数组，并处理深度
void dfs(int p, int f) {
    fa[p][0] = f;  // 设置 p 的父节点为 f
    dep[p] = dep[f] + 1;  // 计算 p 的深度
    for (int i = 1; (1 << i) <= dep[p]; i++) {
        fa[p][i] = fa[fa[p][i - 1]][i - 1];  // 预处理 fa 数组，用于 LCA 查询
    }
    for (int i : tree[p]) {  // 遍历所有子节点，递归调用 dfs
        if (i == f) {
            continue;
        }
        dfs(i, p);
    }
}

int lca(int a, int b){
    if(dep[a] > dep[b]) swap(a, b);
    for(int i = log_2[dep[b] - dep[a]]; i >= 0; i--){
        if(dep[fa[b][i]] >= dep[a]){
            b = fa[b][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = log_2[dep[a]]; i >= 0; i--){
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof(head));  // 初始化

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edge[i] = make_pair(x, y);
        add(x, y);
        add(y, x);
    }

    // 修改6，对每个节点进行 Tarjan 处理，防止不连通
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }

    init();

    // 从 1 开始 DFS，生成 fa 数组和深度
    dfs(1, 0);

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << dep[id[a]] + dep[id[b]] - 2 * dep[lca(id[a], id[b])] << endl;
    }

    return 0;
}
