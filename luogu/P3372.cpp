#include<bits/stdc++.h>
using namespace std;
//记得重构
const int MAXN = 100005;

int n, m, seg_tree[MAXN * 4], num[MAXN], lazy[MAXN * 4];

#define rig ((p << 1) + 1)
#define lef (p << 1)
//#define mid ((l + r) >> 1)
//#define midd ((cl + cr) >> 1)

void build_tree(int l, int r, int p){
    if(l == r) {
        seg_tree[p] = num[l];
    } else {
        int mid = (l + r) / 2;
        
        build_tree(l, mid, lef);
        build_tree(mid + 1, r, rig);
        seg_tree[p] = seg_tree[lef] + seg_tree[rig];
    }
}

void push_down(int p, int l, int r){
    if(lazy[p] != 0){
        int mid = (l + r) / 2;
        int k = lazy[p];
        lazy[rig] += k;
        lazy[lef] += k;
        seg_tree[lef] += (mid - l + 1) * k;
        seg_tree[rig] += (r - mid) * k;
        lazy[p] = 0;
    }
}

void update(int l, int r, int k, int p = 1, int cl = 1, int cr = n){
    if(cl > r || cr < l) {
        return;
    }
    if(cl >= l && cr <= r){
        seg_tree[p] += (cr - cl + 1) * k;
        if(cl < cr) lazy[p] += k;
    } else {
        push_down(p, cl, cr);
        int mmid = (cl + cr) / 2;
        update(l, r, k, lef, cl, mmid);
        update(l, r, k, rig, mmid + 1, cr);
        seg_tree[p] = seg_tree[lef] + seg_tree[rig];
    }
}

int query(int l, int r, int p = 1, int cl = 1, int cr = n){
    if(cl > r || cr < l) {
        return 0;
    }
    if(cl >= l && cr <= r){
        return seg_tree[p];
    } else {
        push_down(p, cl, cr);
        int mmid = (cl + cr) / 2;
        return query(l, r, lef, cl, mmid) + query(l, r, rig, mmid + 1, cr);
    }
}

#undef lef
#undef rig
//#undef mid
//#undef midd

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    build_tree(1, n, 1);
    for(int i = 1; i <= m; i++){
        int tmp, x, y;
        cin >> tmp >> x >> y;
        if(tmp == 1){
            int k;
            cin >> k;
            update(x, y, k);
        } else {
            cout << query(x, y) << endl;
        }
    }
    return 0;
}