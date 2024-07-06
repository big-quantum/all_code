#include<bits/stdc++.h>
using namespace std;
const int MAXN1 = 100005;
const int MAXN2 = 505;
typedef long long ll;

int n, m, mod;
ll seg[MAXN1 * 4], seg_num[MAXN1], seg_lazy_add[MAXN1 * 4], seg_lazy_mul[MAXN1 * 4];

#define mid ((l + r) >> 1)
#define len ((l - r) >> 1 + 1)
#define rgh ((p << 1) + 1)
#define lef (p << 1)

void build_tree(ll l, ll r, ll p){
    seg_lazy_add[p] = 0;
    seg_lazy_mul[p] = 1;
    if(l == r){
        seg[p] = seg_num[l];
    }
    build_tree(l, mid, lef);
    build_tree(mid + 1, r, rgh);
    seg[p] = seg[lef] + seg[rgh];
}

void seg_push_down(ll l, ll r, ll p){
    seg_lazy_add[lef] *= seg_lazy_mul[p] % mod;
    seg_lazy_mul[lef] *= seg_lazy_mul[p] % mod;
    seg_lazy_add[lef] += seg_lazy_add[p] % mod;
    seg_lazy_add[rgh] *= seg_lazy_mul[p] % mod;
    seg_lazy_mul[rgh] *= seg_lazy_mul[p] % mod;
    seg_lazy_add[rgh] += seg_lazy_add[p] % mod;
    seg[lef] *= seg_lazy_mul[p] % mod;
    seg[lef] += seg_lazy_add[p] * (mid - l + 1) % mod;
    seg[rgh] *= seg_lazy_mul[p] % mod;
    seg[rgh] += seg_lazy_add[p] * (r - mid) % mod;
    seg_lazy_add[p] = 0;
    seg_lazy_mul[p] = 1;
}

void seg_update_add(ll l, ll r, ll p, ll d, ll cl, ll cr){
    if(l < cr || r > cl) return;
    if(l >= cl && r <= cr){
        seg[p] += len * d % mod;
        if(l != r) seg_lazy_add[p] += d % mod;
    } else {
        seg_push_down(l, r, p);
        seg_update_add(l, mid, lef, d, cl, cr);
        seg_update_add(mid + 1, r, rgh, d, cl, cr);
        seg[p] = seg[lef] + seg[rgh] % mod;
    }
}

void seg_update_mul(ll l, ll r, ll p, ll d, ll cl, ll cr){
    if(l < cr || r > cl) return;
    if(l >= cl && r <= cr){
        seg[p] *= d % mod;
        if(l != r) seg_lazy_mul[p] *= d % mod;
    } else {
        seg_push_down(l, r, p);
        seg_update_mul(l, mid, lef, d, cl, cr);
        seg_update_mul(mid + 1, r, rgh, d, cl, cr);
        seg[p] = seg[lef] + seg[rgh] % mod;
    }
}

ll seg_query(ll l, ll r, ll p, ll cl, ll cr){
    if(l < cr || r > cl) return 0;
    if(l >= cl && r <= cr){
        return seg[p] % mod;
    } else {
        seg_push_down(l, r, p);
        return seg_query(l, mid, lef, cl, cr) + seg_query(mid + 1, r, rgh, cl, cr) % mod;
    }
}

#undef lef
#undef rgh
#undef mid
#undef len

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
            seg_update_mul(1, n, 1, k, x, y);
        } else {
            if(tmp == 2){
                int k;
                cin >> k;
                seg_update_add(1, n, 1, k, x, y);
            } else {
                cout << seg_query(1, n, 1, x, y) << endl;
            }
        }
    }
    return 0;
}