//
// Created by Lenovo on 2024/10/24.
//

/*
 * 暴力模拟，pts20 ~ 35
 * 区间操作线段树，pts40 ~ 60
 * 答案单调，考虑二分
 * 确定区间上界和下界
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, w;
int a[200005];

//seg
int tree[1000005], lazy[1000005], cnt;

void create(int l, int r, int p){
    if(l == r){
        tree[p] = a[++cnt];
        return;
    }
    int mid = (l + r) / 2, left_tree = p << 1, right_tree = (p << 1) + 1;
    create(l, mid, left_tree);
    create(mid + 1, r, right_tree);
    tree[p] = tree[left_tree] + tree[right_tree];
}

void push(int l, int r, int p){
    int mid = (l + r) / 2, left_tree = p << 1, right_tree = (p << 1) + 1;
    tree[left_tree] += lazy[p] * (mid - l + 1);
    tree[right_tree] += lazy[p] * (r - mid);
    lazy[left_tree] += lazy[p];
    lazy[right_tree] += lazy[p];
    lazy[p] = 0;
}

void add(int l, int r, int d, int p = 1, int cl = 1, int cr = n){
    if(cl > r || cr < l) return;
    if(cl >= l && cr <= r) {
        tree[p] += (cr - cl + 1) * d;
        if(cl != cr) lazy[p] += d;
        return;
    }
    int mid = (cl + cr) / 2, left_tree = p << 1, right_tree = (p << 1) + 1;
    push(cl, cr, p);
    add(l, r, d, left_tree, cl, mid);
    add(l, r, d, right_tree, mid + 1, cr);
    tree[p] = tree[left_tree] + tree[right_tree];
}

int query(int l, int r, int p = 1, int cl = 1, int cr = n){
    if(cl > r || cr < l) return 0;
    if(cl >= l && cr <= r) return tree[p];
    int mid = (cl + cr) / 2, left_tree = p << 1, right_tree = (p << 1) + 1;
    push(cl, cr, p);
    return query(l, r, left_tree, cl, mid) + query(l, r, right_tree, mid + 1, cr);
}

signed main(){
    //freopen("wxyt4.in", "r", stdin);
    //freopen("wxyt4.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &q, &w);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    create(1, n, 1);
    for (int i = 0; i < q; ++i) {
        int l, r, d, mid;
        scanf("%lld%lld%lld", &l, &r, &d);
        add(l, r, d);
        int tot = tree[1], life = w, num = 0, ans = 0, k = 1;
        //cout << tot << endl;
        while(life > tot){
            life -= tot;
            ans += n;
            k <<= 1;
            tot <<= 1;
        }
        l = 1, r = n;
        while(l < r){
            mid = (l + r) / 2;
            if(query(1, mid) * k < life){
                l = mid + 1;
                num = mid;
            } else {
                r = mid;
            }
        }
        printf("%lld\n", num + ans);
    }
    return 0;
}
/*
6 4 75
9 1 4 5 1 4
1 1 1
3 5 3
3 5 1
3 5 3
*/