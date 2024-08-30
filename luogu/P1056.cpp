#include<bits/stdc++.h>
using namespace std;

int m, n, k, l, d;
int yy[1005], xx[1005];

struct node{
    int pos, cnt;
}hh[1005], ll[1005];

bool cmp1(node a, node b){
    return a.cnt > b.cnt;
}

bool cmp2(node a, node b){
    return a.pos < b.pos;
}

int main(){
    cin >> m >> n >> k >> l >> d;
    for(int i = 1; i <= d; i++){
        int dx, dy, x, y;
        cin >> x >> y >> dx >> dy;
        if(x == dx) yy[min(y, dy)]++;
        if(y == dy) xx[min(x, dx)]++;
    }
    for(int i = 1; i <= m; i++){
        hh[i].pos = i;
        hh[i].cnt = xx[i];
    }
    sort(hh + 1, hh + m + 1, cmp1);
    sort(hh + 1, hh + k + 1, cmp2);
    for(int i = 1; i <= n; i++){
        ll[i].pos = i;
        ll[i].cnt = yy[i];
    }
    sort(ll + 1, ll + n + 1, cmp1);
    sort(ll + 1, ll + l + 1, cmp2);
    for(int i = 1; i <= k; i++){
        cout << hh[i].pos << " ";
    }
    cout << endl;
    for(int i = 1; i <= l; i++){
        cout << ll[i].pos << " ";
    }
    return 0;
}