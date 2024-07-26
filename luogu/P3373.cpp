#include<bits/stdc++.h>
using namespace std;
const int MAXN1 = 100005;
const int MAXN2 = 505;
typedef long long ll;

int n, m, mod;
ll seg_tree[MAXN1 * 4], seg_num[MAXN1], seg_lazy_add[MAXN1 * 4], seg_lazy_mul[MAXN1 * 4];

#define mid ((l + r) >> 1)
#define rgh ((p << 1) + 1)
#define lef (p << 1)

void build_tree(ll l, ll r, ll p){
    seg_lazy_add[p] = 0;
    seg_lazy_mul[p] = 1;
    if(l == r){
        seg_tree[p] = seg_num[l] % mod;
        return;
    }
    build_tree(l, mid, lef);
    build_tree(mid + 1, r, rgh);
    seg_tree[p] = (seg_tree[lef] + seg_tree[rgh]) % mod;
}

void seg_push_down(ll l, ll r, ll p){
    seg_lazy_add[lef] = (seg_lazy_add[p] + seg_lazy_mul[p] * seg_lazy_add[lef]) % mod;
    seg_lazy_mul[lef] = (seg_lazy_mul[lef] * seg_lazy_mul[p]) % mod;
    seg_lazy_add[rgh] = (seg_lazy_add[p] + seg_lazy_mul[p] * seg_lazy_add[rgh]) % mod;
    seg_lazy_mul[rgh] = (seg_lazy_mul[rgh] * seg_lazy_mul[p]) % mod;
    seg_tree[lef] = (seg_tree[lef] * seg_lazy_mul[p] + seg_lazy_add[p] * (mid - l + 1)) % mod;
    seg_tree[rgh] = (seg_tree[rgh] * seg_lazy_mul[p] + seg_lazy_add[p] * (r - mid)) % mod;
    seg_lazy_add[p] = 0;
    seg_lazy_mul[p] = 1;
}

void seg_update_add(ll d, ll cl, ll cr, ll l, ll r, ll p){// +
    if(l > cr || r < cl) return;
    if(l >= cl && r <= cr){
        seg_tree[p] = (seg_tree[p] + (r - l + 1) * d) % mod;
        if(l != r) seg_lazy_add[p] = (seg_lazy_add[p] + d) % mod;
    } else {
        seg_push_down(l, r, p);
        seg_update_add(d, cl, cr, l, mid, lef);
        seg_update_add(d, cl, cr, mid + 1, r, rgh);
        seg_tree[p] = (seg_tree[lef] + seg_tree[rgh]) % mod;
    }
}

void seg_update_mul(ll d, ll cl, ll cr, ll l, ll r, ll p){// *
    if(l > cr || r < cl) return;
    if(l >= cl && r <= cr){
        seg_tree[p] = (seg_tree[p] * d) % mod;
        if(l != r){
            seg_lazy_mul[p] = (seg_lazy_mul[p] * d) % mod;
            seg_lazy_add[p] = (seg_lazy_add[p] * d) % mod;
        }
    } else {
        seg_push_down(l, r, p);
        seg_update_mul(d, cl, cr, l, mid, lef);
        seg_update_mul(d, cl, cr, mid + 1, r, rgh);
        seg_tree[p] = (seg_tree[lef] + seg_tree[rgh]) % mod;
    }
}

ll seg_query(ll cl, ll cr, ll l = 1, ll r = n, ll p = 1){// 区间求和
    if(l > cr || r < cl) return 0;
    if(l >= cl && r <= cr){
        return seg_tree[p];
    } else {
        seg_push_down(l, r, p);
        return (seg_query(cl, cr, l, mid, lef) + seg_query(cl, cr, mid + 1, r, rgh)) % mod;
    }
}

#undef lef
#undef rgh
#undef mid

int main(){
    cin >> n >> m >> mod;
    for(int i = 1; i <= n; i++){
        cin >> seg_num[i];
    }
    build_tree(1, n, 1);
    for(int i = 1; i <= m; i++){
        int tmp, x, y;
        cin >> tmp >> x >> y;
        if(tmp == 1){
            int k;
            cin >> k;
            seg_update_mul(k % mod, x, y, 1, n, 1);
        } else {
            if(tmp == 2){
                int k;
                cin >> k;
                seg_update_add(k % mod, x, y, 1, n, 1);
            } else {
                cout << seg_query(x, y) << endl;
            }
        }
    }
    return 0;
}