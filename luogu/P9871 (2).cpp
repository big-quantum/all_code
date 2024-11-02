//
// Created by Administrator on 2024/10/23.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct node {
    int left, right;
} x[N], y[N];


int n, m, c, t, k, d, cnt;
int v[N];

//seg

int tree[N * 4];

void build(int l, int r) {

}

void push_down(int l, int r) {

}

void update(int l, int r) {

}

void query(int l, int r) {

}

int main() {
    cin >> c >> t;
    while(t--) {
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= m; i++) {
            cin >> x[i].left >> x[i].right >> v[i];
            y[cnt++].left = x[i].left;
            y[cnt++].right = x[i].right;
        }
        sort(x + 1, x + m + 1);
        sort(y + 1, y + cnt + 1);
        cnt = y.
    }



    return 0;
}