#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int INF = 0x3f3f3f3f;
const int prime = 998244353;
const int N = 2505;

int n, m, K, pos[N][3], f[N][N];
ull a[N], ans;
vector<int> G[N];
queue<int> Q;

// 快速幂函数，计算 a^b % prime
inline int ksm(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % prime)
        if (b & 1) ret = 1ll * ret * a % prime;
    return ret;
}

// 计算 x 在模 prime 下的逆元
inline int inv(int x) {
    return ksm(x, prime - 2);
}

// 计算 p/q % prime，其中 q 和 prime 互质
inline int rev(int p, int q) {
    return 1LL * p * inv(q) % prime;
}

// 广度优先搜索，计算从 S 到所有点的距离
void bfs(int S) {
    f[S][S] = 1;
    Q.push(S);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (auto v: G[x])
            if (f[S][v] < 0)
                f[S][v] = f[S][x] + 1, Q.push(v);
    }
}

// 检查四个点是否满足条件并更新最大分数
void check(int A, int B, int C, int D) {
    if (!A || !B || !C || !D) return;
    if (A == B || A == C || A == D || B == C || B == D || C == D) return;
    if (f[1][A] > K || f[A][B] > K || f[B][C] > K || f[C][D] > K || f[D][1] > K) return;
    ans = max(ans, a[A] + a[B] + a[C] + a[D]);
}

int main() {
    memset(f, -1, sizeof(f));
    cin >> n >> m >> K;
    K = K + 2;  // 增加 K 的值，为了处理边界情况

    for (int i = 2; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    bfs(1);  // 从家开始搜索

    // 对每个景点进行搜索，并记录可达的前三大分数的点
    for (int i = 2; i <= n; ++i) {
        bfs(i);
        for (int j = 2; j <= n; ++j)
            if (f[i][j] != -1 && f[1][j] != -1 && f[i][j] <= K && f[1][j] <= K && i != j) {
                int x = j;
                if (a[x] > a[pos[i][0]]) swap(x, pos[i][0]);
                if (a[x] > a[pos[i][1]]) swap(x, pos[i][1]);
                if (a[x] > a[pos[i][2]]) swap(x, pos[i][2]);
            }
    }

    // 枚举所有可能的路径并更新最大分数
    for (int B = 2; B <= n; ++B) {
        for (int C = 2; C <= n; ++C) {
            if (B != C && f[B][C] <= K && f[B][C] != -1) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        check(pos[B][i], B, C, pos[C][j]);
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}