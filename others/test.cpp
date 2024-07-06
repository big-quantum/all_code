#include<bits/stdc++.h>
using namespace std;
const int MAXN1 = 100005;
const int MAXN2 = 505;
typedef long long ll;

int n, m, mod;
ll segment_tree[MAXN1 * 4], segment_tree_num[MAXN1], segment_tree_lazy_add[MAXN1 * 4], segment_tree_lazy_mul[MAXN1 * 4];

#define mid ((l + r) >> 1)
#define len ((l - r) >> 1 + 1)
#define rgh ((p << 1) + 1)
#define lef (p << 1)

void build_tree(ll l, ll r, ll p){
    segment_tree_lazy_add[p] = 0;
    segment_tree_lazy_mul[p] = 1;

    if(l == r){
        segment_tree[p] = segment_tree_num[l];
    }
    build_tree(l, mid, lef);
    build_tree(mid + 1, r, rgh);
    segment_tree[p] = segment_tree[lef] + segment_tree[rgh];
}

void segment_tree_push_down(ll l, ll r, ll p){
    segment_tree_lazy_add[lef] += segment_tree_lazy_add[p];
    segment_tree_lazy_mul[lef] += segment_tree_lazy_mul[p];
    segment_tree_lazy_add[rgh] += segment_tree_lazy_add[p];
    segment_tree_lazy_mul[rgh] += segment_tree_lazy_mul[p];
    segment_tree[lef] *= segment_tree_lazy_mul[p] * (mid - l + 1);
    segment_tree[lef] += segment_tree_lazy_add[p] * (mid - l + 1) % mod;
    segment_tree[rgh] *= segment_tree_lazy_mul[p] * (r - mid);
    segment_tree[rgh] += segment_tree_lazy_add[p] * (r - mid)  % mod;
    segment_tree_lazy_add[p] = 0;
    segment_tree_lazy_mul[p] = 1;
}

void segment_tree_update_add(ll l, ll r, ll p, ll d, ll cl, ll cr){// +
    if(l < cr || r > cl) return;
    if(l >= cl && r <= cr){
        segment_tree[p] += len * d;
        if(l != r) segment_tree_lazy_add[p] += d;
    } else {
        segment_tree_push_down(l, r, p);
        segment_tree_update_add(l, mid, lef, d, cl, cr);
        segment_tree_update_add(mid + 1, r, rgh, d, cl, cr);
        segment_tree[p] = segment_tree[lef] + segment_tree[rgh];
    }
}

void segment_tree_update_mul(ll l, ll r, ll p, ll d, ll cl, ll cr){// *
    if(l < cr || r > cl) return;
    if(l >= cl && r <= cr){
        segment_tree[p] *= d;
        if(l != r) segment_tree_lazy_mul[p] *= d;
    } else {
        segment_tree_push_down(l, r, p);
        segment_tree_update_mul(l, mid, lef, d, cl, cr);
        segment_tree_update_mul(mid + 1, r, rgh, d, cl, cr);
        segment_tree[p] = segment_tree[lef] + segment_tree[rgh];
    }
}

ll segment_tree_query(ll l, ll r, ll p, ll cl, ll cr){// 区间求和
    if(l < cr || r > cl) return 0;
    if(l >= cl && r <= cr){
        return segment_tree[p] % mod;
    } else {
        segment_tree_push_down(l, r, p);
        return segment_tree_query(l, mid, lef, cl, cr) + segment_tree_query(mid + 1, r, rgh, cl, cr) % mod;
    }
}

#undef lef
#undef rgh
#undef mid
#undef len

int main(){
    cin >> n >> m >> mod;
    for(int i = 1; i <= n; i++){
        cin >> segment_tree_num[i];
    }
    build_tree(1, n, 1);
    for(int i = 1; i <= m; i++){
        int tmp, x, y;
        cin >> tmp >> x >> y;
        if(tmp == 1){
            int k;
            cin >> k;
            segment_tree_update_mul(1, n, 1, k, x, y);
        } else {
            if(tmp == 2){
                int k;
                cin >> k;
                segment_tree_update_add(1, n, 1, k, x, y);
            } else {
                cout << segment_tree_query(1, n, 1, x, y) << endl;
            }
        }
    }
    return 0;
}