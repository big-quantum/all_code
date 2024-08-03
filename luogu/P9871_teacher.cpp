#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
#define ll long long

int c, t, n, m, k;
ll d, x[MAXN], y[MAXN], v[MAXN], dp[MAXN][2];
vector<pair<int, int>> com[MAXN];
vector<ll> ls;

// 线段树结构体
struct SegmentTree {
    struct Node {
        ll max_val, lazy;
        Node() : max_val(0), lazy(0) {}
    } tree[MAXN * 4];

    void push_down(int p) {
        if (tree[p].lazy) {
            tree[p*2].lazy += tree[p].lazy;
            tree[p*2].max_val += tree[p].lazy;
            tree[p*2+1].lazy += tree[p].lazy;
            tree[p*2+1].max_val += tree[p].lazy;
            tree[p].lazy = 0;
        }
    }

    void update(int p, int l, int r, int ul, int ur, ll val) {
        if (ul <= l && r <= ur) {
            tree[p].max_val += val;
            tree[p].lazy += val;
            return;
        }
        push_down(p);
        int mid = (l + r) / 2;
        if (ul <= mid) {
            update(p*2, l, mid, ul, ur, val);
        }
        if (ur > mid) {
            update(p*2+1, mid+1, r, ul, ur, val);
        }
        tree[p].max_val = max(tree[p*2].max_val, tree[p*2+1].max_val);
    }

    ll query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[p].max_val;
        push_down(p);
        int mid = (l + r) / 2;
        ll res = 0;
        if (ql <= mid) res = max(res, query(p*2, l, mid, ql, qr));
        if (qr > mid) res = max(res, query(p*2+1, mid+1, r, ql, qr));
        return res;
    }
} seg_tree;

void _init() {
    ls.clear();
    for (int i = 0; i < MAXN; i++) {
        com[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    // 初始化线段树
    memset(seg_tree.tree, 0, sizeof(seg_tree.tree));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> t;
    while (t--) {
        cin >> n >> m >> k >> d;
        _init();

        for (int i = 1; i <= m; i++) {
            cin >> x[i] >> y[i] >> v[i];
            ls.push_back(x[i] - y[i] + 1);
            ls.push_back(x[i]);
            // x[i] - y[i]到离散化列表
            ls.push_back(x[i] - y[i]);
        }
        ls.push_back(0);
        sort(ls.begin(), ls.end());
        ls.erase(unique(ls.begin(), ls.end()), ls.end());

        int tot = ls.size() - 1;
        for (int i = 1; i <= m; i++) {
            int l = lower_bound(ls.begin(), ls.end(), x[i] - y[i] + 1) - ls.begin();
            int r = lower_bound(ls.begin(), ls.end(), x[i]) - ls.begin();
            com[r].push_back({l, v[i]});
        }

        ll ans = 0;
        for (int i = 1; i <= tot; i++) {
            for (auto &p : com[i]) {
                // 线段树更新区间
                seg_tree.update(1, 1, tot, 1, p.first, p.second);
            }

            int l = 1;
            while (ls[i] - ls[l] >= k && l <= i) l++;

            // 线段树查询最大值，更新DP状态
            dp[i][1] = seg_tree.query(1, 1, tot, l, i) - ls[i] * d;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            ans = max(ans, max(dp[i][0], dp[i][1]));
            // 线段树更新单点
            seg_tree.update(1, 1, tot, i+1, i+1, dp[i][0] + ls[i] * d);
        }

        cout << ans << "\n";
    }

    return 0;
}
